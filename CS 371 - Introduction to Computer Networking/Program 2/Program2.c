/*****************************************************************************************
	Dylan Jenkins		CS 371	Program 2
	Program2.c		A simple IP forwarding program.

	The program when run with correct parameters is designed to process each
	packet from file parameter and seek to determine the next destination each
	packet should be forwarded to.
*****************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct IP {
	unsigned char A;
	unsigned char B;
	unsigned char C;
	unsigned char D;
};

int main(int argc, char	**argv) {
	FILE *fp1, *fp2, *fp3;

	struct IP Packet;

	int N, Version, Length, Total_Length, Checksum;
	unsigned int Num;
	char ID[20], Mask[20], Next[20];

	fp1 = fopen(argv[2],"r");
	if (fp1 == NULL) {
		printf("Unable to open %s\n", argv[1]);
 		exit(1);
	}

	fp2 = fopen(argv[1], "r");
	if (fp2 == NULL) {
	 	printf("Unable to open %s\n", argv[2]);
	 	exit(1);
	}

	int Count = 0;
	char Response[110];
	fp3 = fopen(argv[3], "w");

	// Reading the first line.
	while (fread(&Packet, 4, 1, fp1)) {
		Version = Packet.A & 0xF0;
		unsigned int CheckCount;

		CheckCount = htons((Packet.A * 256 + Packet.B)) + htons((Packet.C * 256 + Packet.D));
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		Version = Version >> 4;
		Length = Packet.A & 0x0F;
		Length = Length * 4;
		Total_Length = Packet.C * 256 + Packet.D;

		fread(&Packet, 4, 1, fp1);

		CheckCount = CheckCount + htons((Packet.A * 256 + Packet.B));
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		CheckCount = CheckCount + htons((Packet.C * 256 + Packet.D));
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		// Read TTL and Checksum.
		fread(&Packet, 4, 1, fp1);
		int TTL = Packet.A;
		Checksum = Packet.C * 256 + Packet.D;

		CheckCount = CheckCount + htons((Packet.A * 256 + Packet.B));
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		Checksum = Packet.C * 256 + Packet.D;
		fread(&Num, 4, 1, fp1);

		short IP_Firsthalf = Num & 0xFFFF;
		short IP_Secondhalf = (Num & 0xFFFF0000) >> 16;

		CheckCount += IP_Firsthalf;
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		CheckCount += IP_Secondhalf;
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		unsigned char *ip = &Num;
		char SourceIP[50];
		sprintf(SourceIP, " Source IP -> %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);

		// Read the Destination IP.
		N = fread(&Num, 4, 1, fp1);
		IP_Firsthalf = Num & 0xFFFF;
		IP_Secondhalf = (Num & 0xFFFF0000) >> 16;

		CheckCount += IP_Firsthalf;
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		CheckCount += IP_Secondhalf;
		if (CheckCount > 65535) {
			CheckCount -=65535;
		}

		unsigned char *ip1 = &Num;
		char DestinationIP[50];
		char Content[Total_Length - 20];
		sprintf(DestinationIP, " Destination IP -> %d.%d.%d.%d ", ip1[0], ip1[1], ip1[2], ip1[3]);

		// Read the Data.
		N = fread(&Content, Total_Length - 20, 1, fp1);
		unsigned int PreviousMask = 0;
		char Packet_Fwd_IP[25];
		int Dropped_Packet = 0 ;
		TTL = TTL - 1;

		char ttl[20];
		char TotalLength[20];

		sprintf(TotalLength, " Total length -> %d ", Total_Length);
		sprintf(ttl,"TTL -> %d",TTL);

		strcat(Response, ttl);
		strcat(Response, SourceIP);
		strcat(Response, DestinationIP);
		strcat(Response, TotalLength);

		if (TTL ==0) {
			Dropped_Packet = 1;
			strcpy(Packet_Fwd_IP, " Packet was dropped, TTL becomes 0.\n");
		}

		while (fscanf(fp2,"%s %s %s", ID, Mask, Next) != EOF && Dropped_Packet == 0) {
			unsigned int id = inet_addr(ID);
			unsigned int mask = inet_addr(Mask);
			Count++;

			if ((Num & mask) == id) {
				if ( mask >= PreviousMask ) {
					PreviousMask = mask;
					strcpy(Packet_Fwd_IP,Next);
					strcat(Packet_Fwd_IP, " -> Next Hop IP\n");
				}
			}
		}
		Count = 0;
		PreviousMask = 0;
		rewind(fp2);

		printf("Next Hop IP -> %s\n", Packet_Fwd_IP);
		strcat(Response, Packet_Fwd_IP);
		fprintf(fp3, "%s", Response);
		memset(Response, 0, sizeof Response);
		printf("Next Packet\n\n");
	}

	fclose(fp1);
	fclose(fp3);
	fclose(fp2);
	return 0;
}
