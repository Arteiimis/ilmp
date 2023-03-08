.code
	ALIGN 16
ilmp_inv_1_table_:
	; for(i=256;i<512;++i){round(80000h/(i+1/2))}
	dw 2044,2036,2028,2020,2013,2005,1997,1990,1982,1975,1967,1960,1953,1945,1938,1931
	dw 1924,1917,1910,1903,1896,1889,1883,1876,1869,1862,1856,1849,1843,1836,1830,1824
	dw 1817,1811,1805,1799,1792,1786,1780,1774,1768,1762,1756,1751,1745,1739,1733,1727
	dw 1722,1716,1711,1705,1699,1694,1689,1683,1678,1672,1667,1662,1657,1651,1646,1641
	dw 1636,1631,1626,1621,1616,1611,1606,1601,1596,1591,1586,1582,1577,1572,1567,1563
	dw 1558,1553,1549,1544,1540,1535,1531,1526,1522,1517,1513,1509,1504,1500,1496,1492
	dw 1487,1483,1479,1475,1471,1467,1462,1458,1454,1450,1446,1442,1438,1434,1431,1427
	dw 1423,1419,1415,1411,1407,1404,1400,1396,1393,1389,1385,1382,1378,1374,1371,1367
	dw 1364,1360,1357,1353,1350,1346,1343,1339,1336,1332,1329,1326,1322,1319,1316,1312
	dw 1309,1306,1303,1299,1296,1293,1290,1287,1283,1280,1277,1274,1271,1268,1265,1262
	dw 1259,1256,1253,1250,1247,1244,1241,1238,1235,1232,1229,1226,1224,1221,1218,1215
	dw 1212,1209,1207,1204,1201,1198,1196,1193,1190,1188,1185,1182,1180,1177,1174,1172
	dw 1169,1166,1164,1161,1159,1156,1154,1151,1148,1146,1143,1141,1139,1136,1134,1131
	dw 1129,1126,1124,1121,1119,1117,1114,1112,1110,1107,1105,1103,1100,1098,1096,1093
	dw 1091,1089,1087,1084,1082,1080,1078,1075,1073,1071,1069,1067,1065,1062,1060,1058
	dw 1056,1054,1052,1050,1048,1045,1043,1041,1039,1037,1035,1033,1031,1029,1027,1025

	ALIGN 16
ilmp_inv_1_ proc
	mov r9,rcx
	mov rax,rcx
	shr rax,55
	lea rcx,[ilmp_inv_1_table_-512]
	movzx rcx,word ptr[rcx+rax*2]
	;rcx=v0(10,9)=round(80000h/(1/2+(x>>55)))

	mov r8,r9
	mov rax,rcx
	imul ecx,ecx
	shr r8,24
	imul rcx,r8
	shr rcx,41
	shl rax,10
	sub rax,rcx
	;rax=v1(19,17)=(v0<<10)-(v0*v0*(x>>24)>>41)

	mov rcx,800000000000000h
	imul r8,rax
	sub rcx,r8
	imul rcx,rax
	shl rax,15
	sar rcx,44
	add rcx,rax
	;rcx=v2(34,33)=(v1<<15)+(v1*(2^59-v1*(x>>24))>>44)

	mov rax,r9
	mul rcx
	shrd rax,rdx,2
	not rax
	imul rcx
	shl rcx,30
	sar rdx,2
	add rcx,rdx
	;rcx=v3(64,64)=(v2<<30)+(v2*(2^96-(v2*x>>2)-1)>>66)
	;we strictly proved that: -9/8 < v3+2^64 - 2^128/x < 0

	mov rax,r9
	mul rcx
	add rax,r9
	mov rax,rcx
	adc rdx,r9
	sub rax,rdx
	ret
ilmp_inv_1_ endp

	ALIGN 16
ilmp_inv_2_1_ proc
	mov r11,rdx
	mov r10,rcx
	call ilmp_inv_1_
	mov r8,rax
	mov r9,r10
	imul r9,rax		;r9=bh*(inv-2^64) (mod 2^64) =bh*inv m64
	xor rcx,rcx
	mul r11			;rdx:rax=bl*(inv-2^64)
	add r9,r11		;r9=bh*inv+bl m64
	adc rcx,-1		;rcx:r9=bh*inv+bl m128
	add r9,rdx
	adc rcx,0		;rcx:r9:rax=b*inv m192
	js lab_2f
lab_1b:
	dec r8
	sub rax,r11
	sbb r9,r10
	sbb rcx,0
	jns lab_1b
lab_2f:
	mov rax,r8
	ret
ilmp_inv_2_1_ endp
end
