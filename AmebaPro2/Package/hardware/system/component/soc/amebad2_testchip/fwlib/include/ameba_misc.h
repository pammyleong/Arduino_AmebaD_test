#ifndef _AMEBA_MISC_H_
#define _AMEBA_MISC_H_

typedef enum {
	BT_DEDICATED_AFE_PATH,
	BT_SHARED_AFE_PATH,
} BT_RFAFE_PATH_TYPE;

void BT_set_RFAFE_path(BT_RFAFE_PATH_TYPE path);
BT_RFAFE_PATH_TYPE BT_get_RFAFE_path(void);

#endif

