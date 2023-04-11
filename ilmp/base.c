#include"ilmpn.h"

const mp_base_t ilmp_bases_[257]={
	{0x0000000000000000,0x0000000000000000,0x0000000000000000,0,0},
	{0x0000000000000000,0x0000000000000000,0x0000000000000000,0,1},
	{0x0000000000000001,0x0400000000000000,0xffffffffffffffff,64,2},
	{0xa8b8b452291fe821,0x06570068e7ef5a1f,0xa1849cc1a9a9e94f,40,3},
	{0x0000000000000002,0x0800000000000000,0x8000000000000000,32,4},
	{0x6765c793fa10079d,0x0949a784bcd1b8b0,0x6e40d1a4143dcb95,27,5},
	{0x41c21cb8e1000000,0x0a570068e7ef5a1f,0x6308c91b702a7cf5,24,6},
	{0x3642798750226111,0x0b3abb3faa02166d,0x5b3064eb3aa6d389,22,7},
	{0x0000000000000003,0x0c00000000000000,0x5555555555555556,21,8},
	{0xa8b8b452291fe821,0x0cae00d1cfdeb43d,0x50c24e60d4d4f4a8,20,9},
	{0x8ac7230489e80000,0x0d49a784bcd1b8b0,0x4d104d427de7fbcd,19,10},
	{0x4d28cb56c33fa539,0x0dd6753e032ea0f0,0x4a00270775914e89,18,11},
	{0x1eca170c00000000,0x0e570068e7ef5a1f,0x4768ce0d05818e13,17,12},
	{0x780c7372621bd74d,0x0ecd4011c8f1197a,0x452e53e365907bdb,17,13},
	{0x1e39a5057d810000,0x0f3abb3faa02166d,0x433cfffb4b5aae56,16,14},
	{0x5b27ac993df97701,0x0fa0a7eda4c112cf,0x41867711b4f85356,16,15},
	{0x0000000000000004,0x1000000000000000,0x4000000000000000,16,16},
	{0x27b95e997e21d9f1,0x10598fdbeb244c5a,0x3ea16afd58b10967,15,17},
	{0x5da0e1e53c5c8000,0x10ae00d1cfdeb43d,0x3d64598d154dc4df,15,18},
	{0xd2ae3299c1c4aedb,0x10fde0b5c8134052,0x3c43c23018bb5564,15,19},
	{0x16bcc41e90000000,0x1149a784bcd1b8b0,0x3b3b9a42873069c8,14,20},
	{0x2d04b7fdd9c0ef49,0x1191bba891f1708c,0x3a4898f06cf41aca,14,21},
	{0x5658597bcaa24000,0x11d6753e032ea0f0,0x39680b13582e7c19,14,22},
	{0xa0e2073737609371,0x121820a01ac754cc,0x3897b2b751ae561b,14,23},
	{0x0c29e98000000000,0x12570068e7ef5a1f,0x37d5aed131f19c99,13,24},
	{0x14adf4b7320334b9,0x12934f0979a37160,0x372068d20a1ee5cb,13,25},
	{0x226ed36478bfa000,0x12cd4011c8f1197a,0x3676867e5d60de2a,13,26},
	{0x383d9170b85ff80b,0x1305013ab7ce0e5c,0x35d6deeb388df870,13,27},
	{0x5a3c23e39c000000,0x133abb3faa02166d,0x354071d61c77fa2f,13,28},
	{0x8e65137388122bcd,0x136e9291eaa65b4a,0x34b260c5671b18ad,13,29},
	{0xdd41bb36d259e000,0x13a0a7eda4c112cf,0x342be986572b45cd,13,30},
	{0x0aee5720ee830681,0x13d118d66c4d4e56,0x33ac61b998fbbdf3,12,31},
	{0x0000000000000005,0x1400000000000000,0x3333333333333334,12,32},
	{0x172588ad4f5f0981,0x142d75a6eb1dfb0f,0x32bfd90114c12862,12,33},
	{0x211e44f7d02c1000,0x14598fdbeb244c5a,0x3251dcf6169e45f3,12,34},
	{0x2ee56725f06e5c71,0x148462c466d3cf1d,0x31e8d59f180dc631,12,35},
	{0x41c21cb8e1000000,0x14ae00d1cfdeb43d,0x3184648db8153e7b,12,36},
	{0x5b5b57f8a98a5dd1,0x14d67af16da764a0,0x312434e89c35dace,12,37},
	{0x7dcff8986ea31000,0x14fde0b5c8134052,0x30c7fa349460a542,12,38},
	{0xabd4211662a6b2a1,0x1524407ab0e07399,0x306f6f4c8432bc6e,12,39},
	{0xe8d4a51000000000,0x1549a784bcd1b8b0,0x301a557ffbfdd253,12,40},
	{0x07a32956ad081b79,0x156e221cd9d0cde6,0x2fc873d1fda55f3c,11,41},
	{0x09f49aaff0e86800,0x1591bba891f1708c,0x2f799652a4e6dc4a,11,42},
	{0x0ce583bb812d37b3,0x15b47ebf73882a0b,0x2f2d8d8f64460aae,11,43},
	{0x109b79a654c00000,0x15d6753e032ea0f0,0x2ee42e164e8f53a5,11,44},
	{0x1543beff214c8b95,0x15f7a8568cb06ced,0x2e9d500984041dbe,11,45},
	{0x1b149a79459a3800,0x161820a01ac754cc,0x2e58cec05a6a8145,11,46},
	{0x224edfb5434a830f,0x1637e623d2ba01bd,0x2e1688743ef9104d,11,47},
	{0x2b3fb00000000000,0x16570068e7ef5a1f,0x2dd65df7a5835990,11,48},
	{0x3642798750226111,0x1675767f54042cda,0x2d9832759d5369c5,11,49},
	{0x43c33c1937564800,0x16934f0979a37160,0x2d5beb38dcd1394d,11,50},
	{0x54411b2441c3cd8b,0x16b09044d313a679,0x2d216f7943e2ba6b,11,51},
	{0x6851455acd400000,0x16cd4011c8f1197a,0x2ce8a82efbb3ff2d,11,52},
	{0x80a23b117c8feb6d,0x16e963fac9c0ea79,0x2cb17fea7ad7e333,11,53},
	{0x9dff7d32d5dc1800,0x1705013ab7ce0e5c,0x2c7be2b0cfa1ba51,11,54},
	{0xc155af6faeffe6a7,0x17201cc2c00059a0,0x2c47bddba92d7464,11,55},
	{0xebb7392e00000000,0x173abb3faa02166d,0x2c14fffcaa8b131f,11,56},
	{0x050633659656d971,0x1754e11eb0029a70,0x2be398c3a38be054,10,57},
	{0x05fa8624c7fba400,0x176e9291eaa65b4a,0x2bb378e758451069,10,58},
	{0x0717d9faa73c5679,0x1787d3945c340aa7,0x2b8492108be5e5f8,10,59},
	{0x086430aac6100000,0x17a0a7eda4c112cf,0x2b56d6c70d55481c,10,60},
	{0x09e64d9944b57f29,0x17b9133567fead8c,0x2b2a3a608c72ddd6,10,61},
	{0x0ba5ca5392cb0400,0x17d118d66c4d4e56,0x2afeb0f1060c7e42,10,62},
	{0x0dab2ce1d022cd81,0x17e8bc1179e0caaa,0x2ad42f3c9aca595d,10,63},
	{0x0000000000000006,0x1800000000000000,0x2aaaaaaaaaaaaaab,10,64},
	{0x12aeed5fd3e2d281,0x1816e79685c2d22a,0x2a82193a13425884,10,65},
	{0x15c3da1572d50400,0x182d75a6eb1dfb0f,0x2a5a717672f66451,10,66},
	{0x194c05534f75ee29,0x1843ace27e8a7e6b,0x2a33aa6e56d9c71d,10,67},
	{0x1d56299ada100000,0x18598fdbeb244c5a,0x2a0dbbaa3bdfcea5,10,68},
	{0x21f2a089a4ff4f79,0x186f210902b6aeea,0x29e89d244eb4bfb0,10,69},
	{0x2733896c68d9a400,0x188462c466d3cf1d,0x29c44740d7db51e7,10,70},
	{0x2d2cf2c33b533c71,0x1899574f13c570d1,0x29a0b2c743b14d75,10,71},
	{0x33f506e440000000,0x18ae00d1cfdeb43d,0x297dd8dbb7c22a2e,10,72},
	{0x3ba43bec1d062211,0x18c2615e81781d98,0x295bb2f9285c8c1c,10,73},
	{0x4455872d8fd4e400,0x18d67af16da764a0,0x293a3aebe2be1c93,10,74},
	{0x4e2694539f2f6c59,0x18ea4f726192cb7f,0x29196acc815ebda0,10,75},
	{0x5938006c18900000,0x18fde0b5c8134052,0x28f93cfb40f5c22b,10,76},
	{0x65ad9912474aa649,0x1911307dad30b75d,0x28d9ac1badc64118,10,77},
	{0x73ae9ff4241ec400,0x1924407ab0e07399,0x28bab310a196b479,10,78},
	{0x836612ee9c4ce1e1,0x1937124cea4cdece,0x289c4cf88b77446a,10,79},
	{0x9502f90000000000,0x1949a784bcd1b8b0,0x287e7529fb244e92,10,80},
	{0xa8b8b452291fe821,0x195c01a39fbd687a,0x286127306a6a7a54,10,81},
	{0xbebf59a07dab4400,0x196e221cd9d0cde6,0x28445ec93f792b1f,10,82},
	{0xd7540d4093bc3109,0x19800a563161c544,0x282817e1038950fb,10,83},
	{0xf2b96616f1900000,0x1991bba891f1708c,0x280c4e90c9ab1f46,10,84},
	{0x0336de62af2bca35,0x19a33760a7f6050a,0x27f0ff1bc1ee87ce,9,85},
	{0x039235ec33d49600,0x19b47ebf73882a0b,0x27d625ecf571c341,9,86},
	{0x03f674e539585a17,0x19c592fad295b568,0x27bbbf95282fcd46,9,87},
	{0x04645b6958000000,0x19d6753e032ea0f0,0x27a1c8c8ddaf84db,9,88},
	{0x04dcb74afbc49c19,0x19e726aa1e754d21,0x27883e5e7df3f519,9,89},
	{0x056064e1d18d9a00,0x19f7a8568cb06ced,0x276f1d4c9847e90f,9,90},
	{0x05f04fe2cd8a39fb,0x1a07fb5172f32fe7,0x275662a841b30192,9,91},
	{0x068d74421f5c0000,0x1a1820a01ac754cc,0x273e0ba38d15a47c,9,92},
	{0x0738df1f6ab4827d,0x1a28193f543ca874,0x2726158c1b13cf04,9,93},
	{0x07f3afbc9cfb5e00,0x1a37e623d2ba01bd,0x270e7dc9c01d8e9c,9,94},
	{0x08bf187fba88f35f,0x1a47883a84e4f902,0x26f741dd3f070d62,9,95},
	{0x099c600000000000,0x1a570068e7ef5a1f,0x26e05f5f16c2159f,9,96},
	{0x0a8ce21eb6531361,0x1a664f8d569394da,0x26c9d3fe61e80599,9,97},
	{0x0b92112c1a0b6200,0x1a75767f54042cda,0x26b39d7fc6ddab09,9,98},
	{0x0cad7718b8747c43,0x1a84760fd30d552d,0x269db9bc7772a5cd,9,99},
	{0x0de0b6b3a7640000,0x1a934f0979a37160,0x268826a13ef3fde7,9,100},
	{0x0f2d8cf5fe6d74c5,0x1aa20230e1151f1c,0x2672e22d9dbdbda0,9,101},
	{0x1095d25bfa712600,0x1ab09044d313a679,0x265dea72f169cc9a,9,102},
	{0x121b7c4c3698faa7,0x1abef9fe83c135d8,0x26493d93a8cb2515,9,103},
	{0x13c09e8d68000000,0x1acd4011c8f1197a,0x2634d9c282f3ef83,9,104},
	{0x15876ccb0b709ca9,0x1adb632d4ec3293c,0x2620bd41d8933add,9,105},
	{0x17723c2976da2a00,0x1ae963fac9c0ea79,0x260ce662ef04088b,9,106},
	{0x198384e9c259048b,0x1af7431f26a05c82,0x25f95385547353fe,9,107},
	{0x1bbde41dfeec0000,0x1b05013ab7ce0e5c,0x25e60316448db8e2,9,108},
	{0x1e241d6e3337910d,0x1b129ee960ddf169,0x25d2f390152f74f6,9,109},
	{0x20b91cee9901ee00,0x1b201cc2c00059a0,0x25c02379aa9ad044,9,110},
	{0x237ff9079863dfef,0x1b2d7b5a5596bebe,0x25ad9165f2c18908,9,111},
	{0x267bf47000000000,0x1b3abb3faa02166d,0x259b3bf36735c90d,9,112},
	{0x29b08039fbeda7f1,0x1b47dcfe71c303db,0x258921cb955e7694,9,113},
	{0x2d213df34f65f200,0x1b54e11eb0029a70,0x257741a2ac9170b0,9,114},
	{0x30d201d957a7c2d3,0x1b61c824d7990d7b,0x25659a3711bc827e,9,115},
	{0x34c6d52160f40000,0x1b6e9291eaa65b4a,0x25542a50f84b9c3a,9,116},
	{0x3903f855d8f4c755,0x1b7b40e398cfcdb7,0x2542f0c20000377e,9,117},
	{0x3d8de5c8ec59b600,0x1b87d3945c340aa7,0x2531ec64d772bd65,9,118},
	{0x4269541d1ff01337,0x1b944b1b952662c7,0x25211c1ce2fb5a6f,9,119},
	{0x479b38e478000000,0x1ba0a7eda4c112cf,0x25107ed5e7c3ec3c,9,120},
	{0x4d28cb56c33fa539,0x1bacea7c065d41e0,0x25001383bac8a745,9,121},
	{0x5317871fa13aba00,0x1bb9133567fead8c,0x24efd921f390bce4,9,122},
	{0x596d2f44de9fa71b,0x1bc52285c1c02804,0x24dfceb3a26bb204,9,123},
	{0x602fd125c47c0000,0x1bd118d66c4d4e56,0x24cff3430a0341a8,9,124},
	{0x6765c793fa10079d,0x1bdcf68e36752a10,0x24c045e15c149932,9,125},
	{0x6f15be069b847e00,0x1be8bc1179e0caaa,0x24b0c5a679267ae3,9,126},
	{0x7746b3e82a77047f,0x1bf469c22ef8466d,0x24a171b0b31461c9,9,127},
	{0x0000000000000007,0x1c00000000000000,0x2492492492492493,9,128},
	{0x894953f7ea890481,0x1c0b7f285b778429,0x24834b2c9d85cdff,9,129},
	{0x932abffea4848200,0x1c16e79685c2d22a,0x247476f924137502,9,130},
	{0x9dacb687d3d6a163,0x1c2239a3aa266826,0x2465cbc00a40cec1,9,131},
	{0xa8d8102a44840000,0x1c2d75a6eb1dfb0f,0x245748bc980e0428,9,132},
	{0xb4b60f9d140541e5,0x1c389bf5721556be,0x2448ed2f49eb0634,9,133},
	{0xc15065d4856e4600,0x1c43ace27e8a7e6b,0x243ab85da36e3168,9,134},
	{0xceb1363f396d23c7,0x1c4ea8bf749fc70c,0x242ca99203ea8c19,9,135},
	{0xdce31b2488000000,0x1c598fdbeb244c5a,0x241ec01b7cce4ea1,9,136},
	{0xebf12a24bca135c9,0x1c646285b918cd6b,0x2410fb4da9b3b0fd,9,137},
	{0xfbe6f8dbf88f4a00,0x1c6f210902b6aeea,0x24035a808a0f315f,9,138},
	{0x01ef156c084ce761,0x1c79cbb045fe96c9,0x23f5dd105c67ab9e,8,139},
	{0x020c4e3b94a10000,0x1c8462c466d3cf1d,0x23e8825d7b05abb2,8,140},
	{0x022b0695a08ba421,0x1c8ee68cbaa95bdb,0x23db49cc3a0866ff,8,141},
	{0x024b4f35d7a4c100,0x1c99574f13c570d1,0x23ce32c4c6cfb9f6,8,142},
	{0x026d397284975781,0x1ca3b54fcc1fba6a,0x23c13cb308ab6ab8,8,143},
	{0x0290d74100000000,0x1cae00d1cfdeb43d,0x23b4670682c0c70a,8,144},
	{0x02b63b3a37866081,0x1cb83a16a77813fa,0x23a7b13237187c8c,8,145},
	{0x02dd789f4d894100,0x1cc2615e81781d98,0x239b1aac8ac74729,8,146},
	{0x0306a35e51b58721,0x1ccc76e83bf386f9,0x238ea2ef2b24c37a,8,147},
	{0x0331d01712e10000,0x1cd67af16da764a0,0x23824976f4045a27,8,148},
	{0x035f14200a827c61,0x1ce06db66eca6f73,0x23760dc3d6e4d72a,8,149},
	{0x038e858b62216100,0x1cea4f726192cb7f,0x2369ef58c30bd43f,8,150},
	{0x03c03b2c13176a41,0x1cf4205f3a735267,0x235dedbb8e82aa1d,8,151},
	{0x03f44c9b21000000,0x1cfde0b5c8134052,0x23520874dfeb1ffe,8,152},
	{0x042ad23cef3113c1,0x1d0790adbb030097,0x23463f1019228dd8,8,153},
	{0x0463e546b19a2100,0x1d11307dad30b75d,0x233a911b42aa9b3d,8,154},
	{0x049f9fc3f96684e1,0x1d1ac05b291f0706,0x232efe26f7cf33fa,8,155},
	{0x04de1c9c5dc10000,0x1d24407ab0e07399,0x232385c65381b486,8,156},
	{0x051f77994116d2a1,0x1d2db10fc4d9aaf7,0x2318278edde1b39c,8,157},
	{0x0563cd6bb3398100,0x1d37124cea4cdece,0x230ce3187a6c2bea,8,158},
	{0x05ab3bb270beeb01,0x1d406463b1b04498,0x2301b7fd56ca21bc,8,159},
	{0x05f5e10000000000,0x1d49a784bcd1b8b0,0x22f6a5d9da38341d,8,160},
	{0x0643dce0ec16f501,0x1d52dbdfc4c96b38,0x22ebac4c9580d8a0,8,161},
	{0x06954fe21e3e8100,0x1d5c01a39fbd687a,0x22e0caf633834bec,8,162},
	{0x06ea5b9755f440a1,0x1d6518fe4677ba6f,0x22d601796a418887,8,163},
	{0x074322a1c0410000,0x1d6e221cd9d0cde6,0x22cb4f7aec6fd8b5,8,164},
	{0x079fc8b6ae8a46e1,0x1d771d2ba7efb3bf,0x22c0b4a15b80d83f,8,165},
	{0x080072a66d512100,0x1d800a563161c544,0x22b630953a28f77b,8,166},
	{0x086546633b42b9c1,0x1d88e9c72e0b225b,0x22abc300df54ca7d,8,167},
	{0x08ce6b0861000000,0x1d91bba891f1708c,0x22a16b90698da5d3,8,168},
	{0x093c08e16a022441,0x1d9a802391e232f4,0x229729f1b2c83dee,8,169},
	{0x09ae49717f026100,0x1da33760a7f6050a,0x228cfdd444992f79,8,170},
	{0x0a25577ae24c1a61,0x1dabe18797f1f48f,0x2282e6e94ccb8589,8,171},
	{0x0aa15f068e610000,0x1db47ebf73882a0b,0x2278e4e392557ed0,8,172},
	{0x0b228d6bf7577921,0x1dbd0f2e9e79030b,0x226ef7776aa7fd2a,8,173},
	{0x0ba91158ef5c4100,0x1dc592fad295b568,0x22651e5aaf5532d1,8,174},
	{0x0c351ad9aec0b681,0x1dce0a4923a587cd,0x225b5944b40b4695,8,175},
	{0x0cc6db6100000000,0x1dd6753e032ea0f0,0x2251a7ee3cdfcca6,8,176},
	{0x0d5e85d09025c181,0x1dded3fd442364c5,0x22480a1174e913da,8,177},
	{0x0dfc4e816401c100,0x1de726aa1e754d21,0x223e7f69e522683d,8,178},
	{0x0ea06b4c72947221,0x1def6d67328e2208,0x223507b46b988abf,8,179},
	{0x0f4b139365210000,0x1df7a8568cb06ced,0x222ba2af32dbbb9f,8,180},
	{0x0ffc80497d520961,0x1dffd799a83ff9ac,0x22225019a9b4d16d,8,181},
	{0x10b4ebfca1dee100,0x1e07fb5172f32fe7,0x22190fb47b1af173,8,182},
	{0x117492de921fc141,0x1e10139e4fee07ab,0x220fe14186679802,8,183},
	{0x123bb2ce41000000,0x1e1820a01ac754cc,0x2206c483d7c6b787,8,184},
	{0x130a8b6157bdecc1,0x1e2022762a791d50,0x21fdb93fa0e0ccc6,8,185},
	{0x13e15dede0e8a100,0x1e28193f543ca874,0x21f4bf3a31bcdcab,8,186},
	{0x14c06d941c0ca7e1,0x1e300519ee52ed4a,0x21ebd639f1d86585,8,187},
	{0x15a7ff487a810000,0x1e37e623d2ba01bd,0x21e2fe06597361a7,8,188},
	{0x169859ddc5c697a1,0x1e3fbc7a61d024c9,0x21da3667eb0e8ccc,8,189},
	{0x1791c60f6fed0100,0x1e47883a84e4f902,0x21d17f282d1a300f,8,190},
	{0x18948e8c0e6fba01,0x1e4f4980b0b97f01,0x21c8d811a3d3c9e2,8,191},
	{0x19a1000000000000,0x1e570068e7ef5a1f,0x21c040efcb50f859,8,192},
	{0x1ab769203dafc601,0x1e5ead0ebd67e4c3,0x21b7b98f11b61c1b,8,193},
	{0x1bd81ab557f30100,0x1e664f8d569394da,0x21af41bcd19739bb,8,194},
	{0x1d0367a69fed1ba1,0x1e6de7ff6db22c49,0x21a6d9474c81adf1,8,195},
	{0x1e39a5057d810000,0x1e75767f54042cda,0x219e7ffda5ad572b,8,196},
	{0x1f7b2a18f29ac3e1,0x1e7cfb26f3ee02ce,0x219635afdcd3e46e,8,197},
	{0x20c850694c2aa100,0x1e84760fd30d552d,0x218dfa2ec92d0644,8,198},
	{0x222173cc014980c1,0x1e8be7531440e715,0x2185cd4c148e4ae3,8,199},
	{0x2386f26fc1000000,0x1e934f0979a37160,0x217daeda36ad7a5d,8,200},
	{0x24f92ce8af296d41,0x1e9aad4b6679d88a,0x21759eac708452ff,8,201},
	{0x2678863cd0ece100,0x1ea20230e1151f1c,0x216d9c96c7d490d5,8,202},
	{0x280563f0a9472d61,0x1ea94dd194a871b7,0x2165a86e02cb358d,8,203},
	{0x29a02e1406210000,0x1eb09044d313a679,0x215dc207a3c20fe0,8,204},
	{0x2b494f4efe6d2e21,0x1eb7c9a196a28696,0x2155e939e51e8b38,8,205},
	{0x2d0134ef21cbc100,0x1ebef9fe83c135d8,0x214e1ddbb54cd934,8,206},
	{0x2ec84ef4da2ef581,0x1ec62171eaa60909,0x21465fc4b2d68f99,8,207},
	{0x309f102100000000,0x1ecd4011c8f1197a,0x213eaecd2893dd61,8,208},
	{0x3285ee02a1420281,0x1ed455f3cb41e142,0x21370ace09f681c7,8,209},
	{0x347d6104fc324100,0x1edb632d4ec3293c,0x212f73a0ef6db7cc,8,210},
	{0x3685e47dade53d21,0x1ee267d362ad8f7d,0x2127e92012e25005,8,211},
	{0x389ff6bb15610000,0x1ee963fac9c0ea79,0x21206b264c4a39a8,8,212},
	{0x3acc1912ebb57661,0x1ef057b7fbb4caf0,0x2118f98f0e52c290,8,213},
	{0x3d0acff111946100,0x1ef7431f26a05c82,0x211194366320dc67,8,214},
	{0x3f5ca2e692eaf841,0x1efe26443059e2bb,0x210a3af8e926bb79,8,215},
	{0x41c21cb8e1000000,0x1f05013ab7ce0e5c,0x2102edb3d00e29a7,8,216},
	{0x443bcb714399a5c1,0x1f0bd416164f64c3,0x20fbac44d5b6edc3,8,217},
	{0x46ca406c81af2100,0x1f129ee960ddf169,0x20f4768a4348ad09,8,218},
	{0x496e106ac22aaae1,0x1f1961c7696777b7,0x20ed4c62ea57b1f1,8,219},
	{0x4c27d39fa5410000,0x1f201cc2c00059a0,0x20e62dae221c087b,8,220},
	{0x4ef825c296e43ca1,0x1f26cfedb41565d4,0x20df1a4bc4ba6526,8,221},
	{0x51dfa61f5ad88100,0x1f2d7b5a5596bebe,0x20d8121c2c9e506f,8,222},
	{0x54def7a6d2f16901,0x1f341f1a761c09fc,0x20d1150031e5154a,8,223},
	{0x57f6c10000000000,0x1f3abb3faa02166d,0x20ca22d927d8f54e,8,224},
	{0x5b27ac993df97701,0x1f414fdb4982259d,0x20c33b88da7c29ab,8,225},
	{0x5e7268b9bbdf8100,0x1f47dcfe71c303db,0x20bc5ef18c233be0,8,226},
	{0x61d7a7932ff3d6a1,0x1f4e62ba05e418f8,0x20b58cf5f31e4527,8,227},
	{0x65581f53c8c10000,0x1f54e11eb0029a70,0x20aec5793770a74e,8,228},
	{0x68f48a385b8320e1,0x1f5b583ce239065b,0x20a8085ef096d531,8,229},
	{0x6cada69ed07c2100,0x1f61c824d7990d7b,0x20a1558b2359c4b2,8,230},
	{0x70843718cdbf27c1,0x1f6830e69520117c,0x209aace23fafa72f,8,231},
	{0x7479027ea1000000,0x1f6e9291eaa65b4a,0x20940e491ea988d8,8,232},
	{0x788cd40268f39641,0x1f74ed3673c92c82,0x208d79a5006d7a48,8,233},
	{0x7cc07b437ecf6100,0x1f7b40e398cfcdb7,0x2086eedb8a3cead4,8,234},
	{0x8114cc6220762061,0x1f818da88f8bba6d,0x20806dd2c486dcc7,8,235},
	{0x858aa0135be10000,0x1f87d3945c340aa7,0x2079f67119059faf,8,236},
	{0x8a22d3b53c54c321,0x1f8e12b5d23c38ed,0x2073889d50e7bf64,8,237},
	{0x8ede496339f34100,0x1f944b1b952662c7,0x206d243e9303d92a,8,238},
	{0x93bde80aec3a1481,0x1f9a7cd4195120d9,0x2066c93c62170aa9,8,239},
	{0x98c29b8100000000,0x1fa0a7eda4c112cf,0x2060777e9b0db0f7,8,240},
	{0x9ded549671832381,0x1fa6cc764fe63aa6,0x205a2eed73563033,8,241},
	{0xa33f092e0b1ac100,0x1facea7c065d41e0,0x2053ef71773d7e6b,8,242},
	{0xa8b8b452291fe821,0x1fb3020c87acc299,0x204db8f388552eaa,8,243},
	{0xae5b564ac3a10000,0x1fb9133567fead8c,0x20478b5cdbe2bb30,8,244},
	{0xb427f4b3be74c361,0x1fbf1e0410d5e58a,0x20416696f957cfc0,8,245},
	{0xba1f9a938041e100,0x1fc52285c1c02804,0x203b4a8bb8d356e8,8,246},
	{0xc0435871d1110f41,0x1fcb20c7910459cb,0x2035372541ab0f0e,8,247},
	{0xc694446f01000000,0x1fd118d66c4d4e56,0x202f2c4e08fd6dcd,8,248},
	{0xcd137a5b57ac3ec1,0x1fd70abf19511f62,0x202929f0d04b99ea,8,249},
	{0xd3c21bcecceda100,0x1fdcf68e36752a10,0x20232ff8a41b45ec,8,250},
	{0xdaa150410b788de1,0x1fe2dc503b6ec608,0x201d3e50daa036dc,8,251},
	{0xe1b24521be010000,0x1fe8bc1179e0caaa,0x201754e5126d446e,8,252},
	{0xe8f62df12777c1a1,0x1fee95de1df5f5bb,0x201173a1312ca136,8,253},
	{0xf06e445906fc0100,0x1ff469c22ef8466d,0x200b9a71625f3b14,8,254},
	{0xf81bc845c81bf801,0x1ffa37c98fe55f29,0x2005c94216230569,8,255},
	{0x0000000000000008,0x2000000000000000,0x2000000000000000,8,256}
};