#ifndef __RTL8720E_API_RF_H__
#define __RTL8720E_API_RF_H__

/*this file calls harf's APIs*/
enum rtw_hal_status rtw_hal_rf_init(struct rtw_phl_com_t *phl_com, _adapter *padapter);
void rtw_hal_rf_deinit(struct rtw_phl_com_t *phl_com, _adapter *padapter);
#endif