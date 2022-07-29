#ifndef __RTL8730A_API_BB_H__
#define __RTL8730A_API_BB_H__

/*this file calls halbb's APIs*/
void rtw_hal_bb_stainfo_init(_adapter *padapter, struct rtw_phl_stainfo_t *sta);
void rtw_hal_bb_stainfo_deinit(_adapter *padapter, struct rtw_phl_stainfo_t *sta);
u32 rtw_hal_bb_init(struct rtw_phl_com_t *phl_com, _adapter *padapter);
void rtw_hal_bb_deinit(struct rtw_phl_com_t *phl_com, _adapter *padapter);
#endif