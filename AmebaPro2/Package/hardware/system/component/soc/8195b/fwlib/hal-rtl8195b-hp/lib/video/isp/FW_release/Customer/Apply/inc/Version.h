#ifndef _VERSION_H_
#define _VERSION_H_

// header
// FW version struct version
#define FWVER_STRUCT_VER	0x03
#define FWVER_STRUCT_VER_SHIFT 	4
// FW type
#define CODETYPE_ROM		0x00
#define CODETYPE_CACHE		0x01
#define CODETYPE_VD			0x02

#define VERSION_HEADER_ROM	((FWVER_STRUCT_VER<<FWVER_STRUCT_VER_SHIFT)\
		|CODETYPE_ROM)
#define VERSION_HEADER_CA		((FWVER_STRUCT_VER<<FWVER_STRUCT_VER_SHIFT)\
		|CODETYPE_CACHE)
#define VERSION_HEADER_VD		((FWVER_STRUCT_VER<<FWVER_STRUCT_VER_SHIFT)\
		|CODETYPE_VD)

// Magic Tag
#define VERSION_MAGIC_TAG	0x12345678

// IC Name
#define VERSION_RLE0745		0x0745
#define VERSION_RTS3901		0x3901
#define VERSION_RTL8195B	0x8195


#if (_CHIP_ID_ & _RTL8195B_)
#define  BACKENDIC_ID 		VERSION_RTL8195B
#else
#define  BACKENDIC_ID 		VERSION_RTS3901
#endif

// Customer ID: BCD coding. If customer has defined ID use customer's ID, if not, we define ID


// Realtek
#define CN3_REALTEK			0x0643
#define CN3_SWAN			0x0001  // for example

#define CUSTOMER_VENDOR_ID    CN3_REALTEK

// Customer Project No.: BCD coding
#define CUSTOMER_PROJECT_NO		0x0001  //OV2735

// customer code change version
#if (CUSTOMER_VENDOR_ID == CN3_SWAN)
#define FW_CUS_RLS_VER		0x0000	// release version
#define FW_CUS_RVN_VER   	0x0000	// revision version
#else
#define FW_CUS_RLS_VER		0x0000	// release version
#define FW_CUS_RVN_VER   	0x0000	// revision version
#endif
#define FW_CUSTOMER_VERSION	(((U32)FW_CUS_RLS_VER<<16)|FW_CUS_RVN_VER)

#endif

