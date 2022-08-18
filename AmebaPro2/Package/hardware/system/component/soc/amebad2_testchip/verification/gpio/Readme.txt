#########################
#   Register Map        #
#########################
00	DR
04	DDR [0:in 1:out]
30	INT_EN
34	INT_Mask
38	INT_Type: [0:edge 1:level]
3C	INT_POl
40	INT_STS
44	INT_STS_RAW
48	INT_DB
4C	INT_Eoi
50	EXT_
60	ls_sync
68	Both_Edge
78	DB_Clock


------------
input test Items:
1. read bit
2. read port

Test Command:
	gpio in <port> <pin> <loop>
	gpio r porta

------------
output test Itmes:
1. write bit
2. write port

Test Command:
	gpio out <port> <pin> <loop>
	gpio set <port> <pin> port_out <data>

Test Command:
---------------------
interrupt test items:
1. trigger @0x38: edge or level 
		   @0x68: both edge
2. polarity@0x3c: H rising or Low falling
3. debounce@0x48: enable or disable ~@0x78 db_clk
	**lssync  @0x60: sync with pclk at level interrupt.
4. enable  @0x30:
5. mask    @0x34
6. clr_edge@0x4C
7. status  @0x40
   raw_sts @0x44
8. external@0x50

Test Command:
	gpio int <port> <pin> <db_en?> <trigger_type>
## trigger_type:
	0	GPIO_TEST_INT_EDGE_RISING,
	1	GPIO_TEST_INT_EDGE_FALLING,
	2	GPIO_TEST_INT_EDGE_BOTH,
	3	GPIO_TEST_INT_LEVEL_HIGH,
	4	GPIO_TEST_INT_LEVEL_LOW,
## debounce time : (<db_cnt>+1) *2*dbclk
	gpio set <port> <pin> <db_cnt>










