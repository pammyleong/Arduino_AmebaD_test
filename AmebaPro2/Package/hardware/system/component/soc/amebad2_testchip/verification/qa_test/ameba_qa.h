#include "ameba_soc.h"
#include "example_ft_adc_dac.h"

void MIPIDemoShow(void);

void gpio_test_output_144(u32 level);
void gpio_test_output_88(u32 level);

void example_audio_ft_test(void);
void example_fatfs(void);
void adc_key_detect_thread(void);

#ifdef CONFIG_WIFI_EN
#ifdef CONFIG_MP_INCLUDED
void wifi_mp_ctx_thread(void);
#endif
#endif
/*------------------ Memory Test Fucntions -----------------------------*/
void qa_param_thread(u32 *param);
void qa_ddr_thread(u32 *param);


