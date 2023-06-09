// AUTOMATICALLY GENERATED FILE, DON'T EDIT IT !
// ------------------------------------------------------------------------------------------------------------
// CMSIS-STREAM graph for stream-based DSP/ML                                                                  
//   processing of installed software components :                                                             
//   FILTER, DETECTOR                                                                                          
//                                                                                                             
//               +----------------------+         +------------------------+                                   
//    ADC        | noise removal filter |         | detector with decision |       GPIO                        
//    +--------->+ IIR notch, 4th order +-------->+ hold for 1000ms        +------>                            
//               | (int16)              |         | (int16)                |                                   
//               +----------------------+         +------------------------+                                   
//                                                                                                             
// ------------------------------------------------------------------------------------------------------------
0x000000CC, // number of Words in this graph 
0x02000000, // 000 000 [0] 27b RAM address, HW-shared MEM & RAM copy config
0x00003062, // 004 001 [1] Scripts size, NB IOs, number of FORMAT, 
0x00000501, // 008 002 [2] size of LINKEDLIST, number of STREAM_INSTANCES
0x00000405, // 00C 003 [3] number of ARCS, number of DEBUG registers
0x00060001, // 010 004 IO [0]  rx from application
0x00000000, // 014 005    
0x00070803, // 018 006 IO [1]  tx to loudspeaker
0x00000000, // 01C 007    
0x00071005, // 020 008 IO [2]  debug
0x00000000, // 024 009    
0x22000004, // 028 00A Format[0]  input format
0x002FA000, // 02C 00B 
0x00000000, // 030 00C 
0x22000006, // 034 00D Format[1]  output format
0x002FA000, // 038 00E 
0x00000000, // 03C 00F 
0xD091BB44, // 040 010
0xE7E1FAFA, // 044 011
0x2082353F, // 048 012
0xE9D30006, // 04C 013
0xA1E24BA9, // 050 014
0x18F86871, // 054 015
0x474BA8C6, // 058 016
0x8C006D5F, // 05C 017
0xF51F2AFF, // 060 018
0xF702EF5E, // 064 019
0x285954B7, // 068 01A
0xF878C4BE, // 06C 01B
0x0048A009, // 070 ------- FILTER arc 1->2 with TCM
0x00802001, // 074          
0x52000250, // 078 01E SWC MEM 0  
0x020002A0, // 07C 01F SWC MEM 1 
0x00002C01, // 080 020
0x5B567802, // 084 021
0x6671DD2E, // 088 022
0xDD70B021, // 08C 023
0xDD2E5B71, // 090 024
0xF0216671, // 094 025
0x000000DE, // 098 026
0x00000000, // 09C 027
0x00000000, // 0A0 028
0x00000000, // 0A4 029
0x00000000, // 0A8 02A
0x00000000, // 0AC 02B
0x0048A00A, // 0B0 ------- DETECTOR arc 2->3
0x00803002, // 0B4         
0x0A0002C0, // 0B8 02E SWC MEM 0  
0x00000001, // 0BC 02F
0x00000FFF, // 0C0 030
0x41000007, // 0C4 031 Stream Instance [0]  single instance #1
0x04000000, // 0C8 032  
0x04000000, // 0CC 033  
0x02000140, // 0D0 034 ARC[0] ARC #0
0x00000004, // 0D4 035
0x00000000, // 0D8 036
0x00000000, // 0DC 037
0x0A000150, // 0E0 038 ARC[1] input=>filter
0x00000020, // 0E4 039
0x00000000, // 0E8 03A
0x00000000, // 0EC 03B
0x0A000170, // 0F0 03C ARC[2] filter=>detector
0x00000020, // 0F4 03D
0x00000000, // 0F8 03E
0x00000000, // 0FC 03F
0x0A000190, // 100 040 ARC[3] detect=>output
0x00000020, // 104 041
0x00000000, // 108 042
0x00000000, // 10C 043
0x0A0001D0, // 110 044 ARC[4] debug trace
0x00000080, // 114 045
0x00000000, // 118 046
0x00000000, // 11C 047
0x00000000, // 120 048
0x00000000, // 124 049
0x00000000, // 128 04A
0x00000000, // 12C 04B
0x00000000, // 130 04C
0x00000000, // 134 04D
0x00000000, // 138 04E
0x00000000, // 13C 04F
0x00000000, // 140 050
0x00000000, // 144 051
0x00000000, // 148 052
0x00000000, // 14C 053
0x00000000, // 150 054
0x00000000, // 154 055
0x00000000, // 158 056
0x00000000, // 15C 057
0x00000000, // 160 058
0x00000000, // 164 059
0x00000000, // 168 05A
0x00000000, // 16C 05B
0x00000000, // 170 05C
0x00000000, // 174 05D
0x00000000, // 178 05E
0x00000000, // 17C 05F
0x00000000, // 180 060
0x00000000, // 184 061
0x00000000, // 188 062
0x00000000, // 18C 063
0x00000000, // 190 064
0x00000000, // 194 065
0x00000000, // 198 066
0x00000000, // 19C 067
0x00000000, // 1A0 068
0x00000000, // 1A4 069
0x00000000, // 1A8 06A
0x00000000, // 1AC 06B
0x00000000, // 1B0 06C
0x00000000, // 1B4 06D
0x00000000, // 1B8 06E
0x00000000, // 1BC 06F
0x00000000, // 1C0 070
0x00000000, // 1C4 071
0x00000000, // 1C8 072
0x00000000, // 1CC 073
0x00000000, // 1D0 074
0x00000000, // 1D4 075
0x00000000, // 1D8 076
0x00000000, // 1DC 077
0x00000000, // 1E0 078
0x00000000, // 1E4 079
0x00000000, // 1E8 07A
0x00000000, // 1EC 07B
0x00000000, // 1F0 07C
0x00000000, // 1F4 07D
0x00000000, // 1F8 07E
0x00000000, // 1FC 07F
0x00000000, // 200 080
0x00000000, // 204 081
0x00000000, // 208 082
0x00000000, // 20C 083
0x00000000, // 210 084
0x00000000, // 214 085
0x00000000, // 218 086
0x00000000, // 21C 087
0x00000000, // 220 088
0x00000000, // 224 089
0x00000000, // 228 08A
0x00000000, // 22C 08B
0x00000000, // 230 08C
0x00000000, // 234 08D
0x00000000, // 238 08E
0x00000000, // 23C 08F
0x00000000, // 240 090
0x00000000, // 244 091
0x00000000, // 248 092
0x00000000, // 24C 093
0x11110250, // 250 094
0x00000000, // 254 095
0x00000000, // 258 096
0x00000000, // 25C 097
0x00000000, // 260 098
0x00000000, // 264 099
0x00000000, // 268 09A
0x00000000, // 26C 09B
0x00000000, // 270 09C
0x00000000, // 274 09D
0x00000000, // 278 09E
0x00000000, // 27C 09F
0x00000000, // 280 0A0
0x00000000, // 284 0A1
0x00000000, // 288 0A2
0x00000000, // 28C 0A3
0x00000000, // 290 0A4
0x00000000, // 294 0A5
0x00000000, // 298 0A6
0x00000000, // 29C 0A7
0x111102A0, // 2A0 0A8
0x00000000, // 2A4 0A9
0x00000000, // 2A8 0AA
0x00000000, // 2AC 0AB
0x00000000, // 2B0 0AC
0x00000000, // 2B4 0AD
0x00000000, // 2B8 0AE
0x00000000, // 2BC 0AF
0x111102C0, // 2C0 0B0
0x00000000, // 2C4 0B1
0x00000000, // 2C8 0B2
0x00000000, // 2CC 0B3
0x00000000, // 2D0 0B4
0x00000000, // 2D4 0B5
0x00000000, // 2D8 0B6
0x00000000, // 2DC 0B7
0x00000000, // 2E0 0B8
0x00000000, // 2E4 0B9
0x00000000, // 2E8 0BA
0x00000000, // 2EC 0BB
0x00000000, // 2F0 0BC
0x00000000, // 2F4 0BD
0x00000000, // 2F8 0BE
0x00000000, // 2FC 0BF
0x00000000, // 300 0C0
0x00000000, // 304 0C1
0x00000000, // 308 0C2
0x00000000, // 30C 0C3
0x00000000, // 310 0C4
0x00000000, // 314 0C5
0x00000000, // 318 0C6
0x00000000, // 31C 0C7
0x00000000, // 320 0C8
0x00000000, // 324 0C9
0x00000000, // 328 0CA
0x00000000, // 32C 0CB
