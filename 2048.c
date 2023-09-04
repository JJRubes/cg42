#define _ -1
int board[16] = {
//  +-------+-------+-------+-------+
//  |       |       |       |       |
          4 ,     2 ,    -1 ,    -1 ,
//  |       |       |       |       |
//  +-------+-------+-------+-------+
//  |       |       |       |       |
          2 ,    -1 ,    -1 ,    -1 ,
//  |       |       |       |       |
//  +-------+-------+-------+-------+
//  |       |       |       |       |
          4 ,    -1 ,    -1 ,    -1 ,
//  |       |       |       |       |
//  +-------+-------+-------+-------+
//  |       |       |       |       |
          4 ,     2 ,     2 ,    -1 ,
//  |       |       |       |       |
//  +-------+-------+-------+-------+
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef LEFT
#define val(i, j) board[i * 4 + (0 + j)]
#endif
#ifdef RIGHT
#define val(i, j) board[i * 4 + (3 - j)]
#endif
#ifdef DOWN
#define val(i, j) board[i + (3 - j) * 4]
#endif
#ifdef UP
#define val(i, j) board[i + (0 + j) * 4]
#endif
#define s(x) #x
#define S(x) #x " " s(x)

#define AA "#define "
#define AB "//  |       |       |       |       |\n"
#define AC "//  +-------+-------+-------+-------+\n"
#define AD int gameOver() {
#define AE for(int i = 0; i < 4; i++) {
#define AF int prevRow = -1; int prevCol = -1;
#define AG for(int j = 0; j < 4; j++) {
#define AL } } return 1; }

#define AM void addRandom() {
#define AN while(1) { int index = rand() % 16;
#define AO if(board[index] == -1) {
#define AP board[index] = rand() % 100 < 90 ? 2 : 4;
#define AQ return; } } }

#define AR int move() {
#define AS int changed = 0;
#define AT for(int i = 0; i < 4; i++) {
#define AU int k = 0;
#define AV for(int j = 1; j < 4; j++) {
#define BD } else { k++;
#define BG } } } } return changed; }

#define BH void newGame() {
#define BI for(int i = 0; i < 16; i++) {
#define BJ board[i] = -1;
#define BK } addRandom(); addRandom(); }

#define BL int main() {
#define BM "//  +------ *** Game Over *** ------+\n"
#define BN char* mid = (gameOver() ? "//  +------ *** Game Over *** ------+\n" : "//  +-------+-------+-------+-------+\n");
#define BO newGame();
#define BP srand(time(((void *)0)));
#define BQ if(move()) addRandom();
#define BR ,
#define BS "%1$s%2$s\nint board[16] = {\n%3$s%4$s%5$11d ,%6$6d ,%7$6d ,%8$6d ,\n"
#define BT "%4$s%3$s%4$s%9$11d ,%10$6d ,%11$6d ,%12$6d ,\n%4$s%3$s%4$s%13$11d ,%14$6d ,%15$6d ,%16$6d ,\n"
#define BU "%4$s%3$s%4$s%17$11d ,%18$6d ,%19$6d ,%20$6d ,\n%4$s%3$s};\n\n"
#define BV "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <time.h>\n"
#define BW "#ifdef LEFT\n#define val(i, j) board[i * 4 + (0 + j)]\n#endif\n"
#define BX "#ifdef RIGHT\n#define val(i, j) board[i * 4 + (3 - j)]\n#endif\n"
#define BY "#ifdef DOWN\n#define val(i, j) board[i + (3 - j) * 4]\n#endif\n"
#define BZ "#ifdef UP\n#define val(i, j) board[i + (0 + j) * 4]\n#endif\n"
#define CA "#define s(x) #x\n"
#define CB "#define S(x) #x \" \" s(x)\n\n"
#define CC "%1$s%21$s\n%1$s%22$s\n%1$s%23$s\n%1$s%24$s\n%1$s%25$s\n%1$s%26$s\n"
#define CD "%1$s%27$s\n%1$s%28$s\n\n%1$s%29$s\n%1$s%30$s\n%1$s%31$s\n%1$s%32$s\n"
#define CE "%1$s%33$s\n\n%1$s%34$s\n%1$s%35$s\n%1$s%36$s\n%1$s%37$s\n%1$s%38$s\n"
#define CF "%1$s%39$s\n%1$s%40$s\n\n%1$s%41$s\n%1$s%42$s\n%1$s%43$s\n%1$s%44$s\n\n"
#define CG "%1$s%45$s\n%1$s%46$s\n%1$s%47$s\n%1$s%48$s\n%1$s%49$s\n%1$s%50$s\n#define BR ,\n"
#define CH "%1$s%51$s\n%1$s%52$s\n%1$s%53$s\n%1$s%54$s\n%1$s%55$s\n%1$s%56$s\n"
#define CI "%1$s%57$s\n%1$s%58$s\n%1$s%59$s\n%1$s%60$s\n%1$s%61$s\n"
#define CJ "%1$s%62$s\n%1$s%63$s\n%1$s%64$s\n%1$s%65$s\n%1$s%66$s\n%1$s%67$s\n"
#define CK "%1$s%68$s\n%1$s%69$s\n%1$s%70$s\n%1$s%71$s\n%1$s%72$s\n%1$s%73$s\n"
#define CL "%1$s%74$s\n%1$s%75$s\n%1$s%76$s\n%1$s%77$s\n%1$s%78$s\n%1$s%79$s\n"
#define CM "%1$s%80$s\n%1$s%81$s\n%1$s%82$s\n%1$s%83$s\n%1$s%84$s\n%1$s%85$s\n"
#define CN "%1$s%86$s\n%1$s%87$s\n%1$s%88$s\n%1$s%89$s\n%1$s%90$s\n%1$s%91$s\n"
#define CO "%1$s%92$s\n%1$s%93$s\n%1$s%94$s\n%1$s%95$s\n%1$s%96$s\n%1$s%97$s\n"
#define CP "%1$s%98$s\n%1$s%99$s\n%1$s%100$s\n%1$s%101$s\n%1$s%102$s\n%1$s%103$s\n"
#define CQ "%1$s%104$s\n%1$s%105$s\n%1$s%106$s\n"
#define CR ""
#define CS "AD\nAE\nAF\nAG\nif(val(i, j) == _ || val(i, j) == prevRow) return 0;\nprevRow = val(i, j);\nif(val(j, i) == _ || val(j, i) == prevCol) return 0;\nprevCol = val(j, j);\nAL\nAM\nAN\nAO\nAP\nAQ\nAR\nAS\nAT\n"
#define CT "AU\nAV\nif (val(i, j) == _) continue;\nif (val(i, k) == _) {\nval(i, k) = val(i, j);\nval(i, j) = _; changed = 1;\n} else if (val(i, k) == val(i, j)) {\nval(i, k) += val(i, j);\nval(i, j) = _; k++; changed = 1;\nBD\nval(i, k) = val(i, j);\nif(k != j) { val(i, j) = _;\nBG\nBH\nBI\nBJ\nBK\n"
#define CU "BL\nBN\n#ifdef NEW_GAME\nBO\n#else\nBP\nBQ\n#endif\nprintf(\nBS\nBT\nBU\n"
#define CV "BV\nBW\nBX\nBY\nBZ\nCA\nCB\nCC\nCD\nCE\nCF\nCG\nCH\nCI\nCJ\nCK\nCL\n"
#define CW "CM\nCN\nCO\nCP\nCQ\nCR\nCS\nCT\nCU\nCV\nCW\nCX,\nCY\nCZ\nDA\nDB\nDC\n"
#define CX "DD\nDE\nDF\nDG\nDH\nDI\nDJ\nDK\nDL\nDM\nDN\nDO\nDP\nDQ\nDR\nDS\nDT\nDU);}"
#define CY AA, S(_), AC, AB, board[0], board[1], board[2], board[3], board[4], board[5], board[6],
#define CZ board[7], board[8], board[9], board[10], board[11], board[12], board[13], board[14], board[15], S(AA),
#define DA S(AB), S(AC), S(AD), S(AE), S(AF), S(AG),
#define DB S(AL), S(AM), S(AN), S(AO), S(AP), S(AQ), S(AR), S(AS), S(AT), S(AU),
#define DC S(AV), S(BD),
#define DD S(BG), S(BH), S(BI), S(BJ), S(BK),
#define DE S(BL), S(BM), S(BN), S(BO),
#define DF S(BP), S(BQ), S(BS), S(BT), S(BU), S(BV), S(BW), S(BX), S(BY),
#define DG S(BZ), S(CA), S(CB), S(CC), S(CD), S(CE), S(CF), S(CG), S(CH), S(CI),
#define DH S(CJ), S(CK), S(CL), S(CM), S(CN), S(CO), S(CP), S(CQ), S(CR), S(CS),
#define DI S(CT), S(CU), S(CV), S(CW), S(CX), DK, DL, DM, DN, DO, DP, DQ, DR, DS,
#define DJ DT, DU, DV, S(DK), S(DL), S(DM), S(DN), S(DO), S(DP), S(DQ), S(DR), S(DS), S(DT), S(DU), S(DV),
#define DK "CY AA, S(_), AC, AB, board[0], board[1], board[2], board[3], board[4], board[5], board[6],"
#define DL "CZ board[7], board[8], board[9], board[10], board[11], board[12], board[13], board[14], board[15], S(AA),"
#define DM "DA S(AB), S(AC), S(AD), S(AE), S(AF), S(AG),"
#define DN "DB S(AL), S(AM), S(AN), S(AO), S(AP), S(AQ), S(AR), S(AS), S(AT), S(AU),"
#define DO "DC S(AV), S(BD),"
#define DP "DD S(BG), S(BH), S(BI), S(BJ), S(BK),"
#define DQ "DE S(BL), S(BM), S(BN), S(BO),"
#define DR "DF S(BP), S(BQ), S(BS), S(BT), S(BU), S(BV), S(BW), S(BX), S(BY),"
#define DS "DG S(BZ), S(CA), S(CB), S(CC), S(CD), S(CE), S(CF), S(CG), S(CH), S(CI),"
#define DT "DH S(CJ), S(CK), S(CL), S(CM), S(CN), S(CO), S(CP), S(CQ), S(CR), S(CS),"
#define DU "DI S(CT), S(CU), S(CV), S(CW), S(CX), DK, DL, DM, DN, DO, DP, DQ, DR, DS,"
#define DV "DJ DT, DU, DV, S(DK), S(DL), S(DM), S(DN), S(DO), S(DP), S(DQ), S(DR), S(DS), S(DT), S(DU), S(DV),"
AD
AE
AF
AG
if(val(i, j) == _ || val(i, j) == prevRow) return 0;
prevRow = val(i, j);
if(val(j, i) == _ || val(j, i) == prevCol) return 0;
prevCol = val(j, j);
AL
AM
AN
AO
AP
AQ
AR
AS
AT
AU
AV
if (val(i, j) == _) continue;
if (val(i, k) == _) {
val(i, k) = val(i, j);
val(i, j) = _; changed = 1;
} else if (val(i, k) == val(i, j)) {
val(i, k) += val(i, j);
val(i, j) = _; k++; changed = 1;
BD
val(i, k) = val(i, j);
if(k != j) { val(i, j) = _;
BG
BH
BI
BJ
BK
BL
BN
#ifdef NEW_GAME
BO
#else
BP
BQ
#endif
printf(
BS
BT
BU
BV
BW
BX
BY
BZ
CA
CB
CC
CD
CE
CF
CG
CH
CI
CJ
CK
CL
CM
CN
CO
CP
CQ
CR
CS
CT
CU
CV
CW
CX,
CY
CZ
DA
DB
DC
DD
DE
DF
DG
DH
DI
DJ
DK
DL
DM
DN
DO
DP
DQ
DR
DS
DT
DU);}