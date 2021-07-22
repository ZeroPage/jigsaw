#include <stdio.h>
#include <Windows.h>

const char* jigsaw[] = {
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM8Z7777ZDMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNI++??++====+??++?$MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMM7????+=~~~~~~~~~~==+++++?OMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMZ?==~~~~~~::::::::::::~~~~~==+?NMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMM8+=~~:::::::::::::::::::::::::~~~=?MMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMM+~~::::::,::,,,,,,,,,,,,,,,::::::::~=7MMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMM$=~:::::,,,,,,,,,,,,,,,,,,,,,,,,,::::::~+MMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMM?~::,,,,,.,,,.,,,,,,,,,,,,,,,,,,,,,,,,,::~=NMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMM+::,,,,,,,,.....,..,..,,,,,..,,,,,,,,.,,,,,:~MMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMM7:,,,,,,,.,......,..,....,,......,.,,,...,,,,,=MMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMN~,,,,,...,,.............,,.........,,.....,,,,:IMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMM=:,,,,,.....,,,........,.,......,,,,.,,....,,,,,:NMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMO~,,,,,........,,,,...........,,,.,,,..,,......,,,=MMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMM=::,,,..............,,....,,,..............,,.,,,,:NMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMN:......,,,,...............,......................,:7MMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM~,::=?7$8DDDO7I?+:,,.....,,.....,,:=++?7ZZ$7II?~,,.,=MMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM..:~$ODNDMNMMMMDDN7I:....::....=?INMMMMMMMMN8MZ7II=:.MMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM...:=7DDM8OMMMMMNNMDM=,,~::,,+7MDMMNMMMMMZOODMN$+:...NMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM:,.,~7MMD8OMMMMMDDNMMI,,...,:~ZMMMNDMMMMM$OOMMM8~,..,NMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM~:::~=?NNMNDMMMNNNMDM?,,...,,:IMMMNNNMMMNDMM8NM7=:,,:NMMMMMMMMMMMMM",
	"MMMMMMMMMMMMM:,,:,:~=IMMMMMMMMMDMN~,,...,,:+MMMMMMMMMMMMMZ+~:::::~OMMMMMMMMMMMMM",
	"MMMMMMMMMMMM,,,,,,,,::~=7NMMMMMN7~,,,....,,:+DMMNNNNMMD?~::,,,,,,,7MMMMMMMMMMMMM",
	"MMMMMMMMMMN=,~7Z?,,,,,,,:::~==~~:,,,.....,,:~=++??+~::,,,,,I$IIZ?,:ONMMMMMMMMMMM",
	"MMMMMMMMMMM7.....~O,...,,,,:::::,,..... ..,,:::::,,,,,,,.?=.:$Z+.7,?NMMMMMMMMMMM",
	"MMMMMMMMMM=.$,.I7,.8,,.,,,,,,,,,,... .......,::,,,......:I,Z~...$,$,NNMMMMMMMMMM",
	"MMMMMMMMMM:Z.$?7.Z,~Z,,,,,,:::::.... .. ....,:::,......,7,I?+7+,.$.,NNMMMMMMMMMM",
	"MMMMMMMMMMIO....$7I,O,,,,,,:::::.... ........:~::...,,,,I,Z~7?...$:,MMMMMMMMMMMM",
	"MMMMMMMMMMM+?.,OIO::8::::::~~~::....... ....,:~~~:::,,,,I:=O:ZZ7$,$=MMMMMMMMMMMM",
	"MMMMMMMMMMMNI+I:IO:$$~~~~~=~~~::,...... ....:~~~~~:~~:::~Z:+87::IOZMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMZ?$=~8Z==++++===~.,,...........,~~==========+DZ==+~I?MMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMNMO7II?+??7I?+,,..,...........,:.,~+???+++??????IOMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMM~::~~~=OZ:,:.,,,...........,,,,:~=+$$+++=:::~DMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMI:~::~~~Z8:,,..................:~=8I=~~~::::?MMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMM~:~:::::?NZ=.,,...........,:,:?ZM=~~~~~~~:~7MMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMM$~:::::::?MMM$=,,::~=~~:~~~$OMMD=:~~::::::?MMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMM?~::::::,+DMMMMMMMNNNNMMMMMMM7,::::~:::~+MMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMM+~::::,::?O7$ZZZZ$$$77$Z7IM?:::::::::~+MMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMM~:::,::::8:::~=~======~~=OI:::::,:::=NMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMN~:::,,,~O,,.:~=~====::,.:Z:,,,::::~8MMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMM7~::,,,O~.,,,,:::,,.....,8:,,,:::~?MMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMM=::,,:8,.....,:,,.......?=,,,::~+MMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMM~:::=7,,.,...::.......,,Z:::::=MMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMM7:::$:,,.,...,,......,,,Z~:::=DMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMM~::O::,.,,,.:,.....,,::?I::~IMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMD+I8~:,,,,,.,,..,,,::::=$=~+MMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMM+~:,,,,,,,,..,::::~+MNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+::,,,,,,,,...::~+7MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+=:,,,,:,,,.:==?OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM$777ONZIIII7MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
};
const char* jigsawMoving[] = {
	"MMMMMMMMMMMMMMMMMMMM+~::::,::?O7$ZZZZ$$$77$Z7IM?:::::::::~+MMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMM~:::,::::88888888888888888I:::::,:::=NMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMN~:::,,,~O8888888888888888Z:,,,::::~8MMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMM7~::,,,O888888888888888888:,,,:::~?MMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMM=::,,:888888888888888888?=,,,::~+MMMMMMMMMMMMMMMMMMMMMMMM",
	"MMMMMMMMMMMMMMMMMMMMMMMM~:::=7888888888888888888Z:::::=MMMMMMMMMMMMMMMMMMMMMMMMM"
};
const int upper = 37;
const int movingLines = sizeof(jigsawMoving) / sizeof(char*);
const int jigsawLines = sizeof(jigsaw) / sizeof(char*);
void clearConsole();
void printJigsawLine(int round, int ln);

void printJigsaw(int rounds) {

	int movingNow = 0;
	int doIncrease = TRUE;
	for(int i = 0; i < rounds; i++) {
		for (int j = 0; j < jigsawLines; j++) {
			printJigsawLine(i, j);
			printf("\n");
		}
		Sleep(30);
		clearConsole();
		/*for (int i = 0; i < upper; i++) {
			printf(jigsaw[i]);
			printf("\n");
		}
		for (int i = 0; i < movingNow; i++) {
			printf(jigsaw[upper + i + 1]);
			printf("\n");
		}
		printf(jigsawMoving[movingNow]);
		printf("\n");
		for (int i = upper + movingNow + 1; i < jigsawLines; i++) {
			printf(jigsaw[i]);
			printf("\n");
		}
		Sleep(10);
		clearConsole();
		if (doIncrease)
			movingNow++;
		else
			movingNow--;
		if (doIncrease && movingNow == movingLines - 1)
			doIncrease = FALSE;
		else if (!doIncrease && movingNow == 0)
			doIncrease = TRUE;*/
	}
}
void printJigsawLine(int round, int ln) {
	int movingNow = (round / movingLines % 2 == 1 ? movingLines - 1 : 0) - (round % movingLines);
	if (movingNow < 0) movingNow = -movingNow;
	int line = 0;
	for (int i = 0; i < upper; i++) {
		if (line++ == ln) {
			printf(jigsaw[i]);
			return;
		}
	}
	for (int i = 0; i < movingNow; i++) {
		if (line++ == ln) {
			printf(jigsaw[upper + i + 1]);
			return;
		}
	}
	if (line++ == ln) {
		printf(jigsawMoving[movingNow]);
		return;
	}
	for (int i = upper + movingNow + 1; i < jigsawLines; i++) {
		if (line++ == ln) {
			printf(jigsaw[i]);
			return;
		}
	}

}
void clearConsole() {
	system("cls");
}