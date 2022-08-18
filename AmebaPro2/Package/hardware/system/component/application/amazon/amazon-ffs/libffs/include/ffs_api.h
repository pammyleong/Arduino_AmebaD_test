#ifndef FFS_API_H_
#define FFS_API_H_

#include "ffs/compat/ffs_linux_user_context.h"
#include "ffs/linux/ffs_wifi_manager.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_task.h"

void user_context_init(FfsUserContext_t *userContext);
void ffs_init_wifi_switcher(FfsUserContext_t *userContext);
//void ffs_provisionee_task(FfsUserContext_t userContext);
void ffs_provisionee_task(void);
#endif /* FFS_API_H_ */