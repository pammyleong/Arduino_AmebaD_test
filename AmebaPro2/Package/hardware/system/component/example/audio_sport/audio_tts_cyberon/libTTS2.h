#ifndef	__LIB_TTS_H
#define	__LIB_TTS_H

#ifndef HANDLE
#define HANDLE void*
#endif

typedef int (*TTSCallback)(void *pVoid, int nFlag, char *pchData, int nSize);
typedef enum {
	TTS_RET_STOP = -11,
	TTS_RET_PARAM_ERROR = -10,
	TTS_RET_MEMORY_FAIL = -9,
	TTS_RET_DONE = -6,
	TTS_RET_OK	= 0,
	TTS_RET_LANGUAGE_UNSUPPORT = -101
} TTS_RETURN;

typedef enum {
	TTS_CB_WAV,
	TTS_CB_TEXT,
	TTS_CB_MAX

} TTS_CALL_BACK;

typedef enum {
	TTS_SAMPLE_RATE_16K = 0,
	TTS_SAMPLE_RATE_48K = 1,
	TTS_SAMPLE_RATE_32K = 2,
} TTS_SAMPLE_RATE;

typedef struct {
	int LangId;
	const int *pProsody;
	const int *pVoice;
	const int *pNLP; //optional,
	const int *pBinTextNormalize; //optional, text normalize(tn)
	const int *pBiProsody; //second language prosody
	const int *pBiVoice; //second language voice
	const int *pBiNLP; //optional, second language nlp
	const int *pBiBinTextNormalize; //optional, text normalize(tn)
	int BiLangId;
} LangSetting;

HANDLE TTS_Init(void *mem, int memSize,  int bufferSize, const LangSetting *setting); // bufferSize: 256~ 8192
TTS_RETURN  TTS_SetLanguage(HANDLE hTTS, const LangSetting *setting);
TTS_RETURN TTS_Start(HANDLE hTTS, const char *pszText, TTSCallback pfnCallback, void *pvVoid);
TTS_RETURN TTS_Next(HANDLE hTTS);
TTS_RETURN TTS_SetVolume(HANDLE hTTS, int nVolume); //value: 0 ~ 500; default 100
TTS_RETURN TTS_SetPitch(HANDLE hTTS, int nPitch); //value: 50 ~ 200; default 100
TTS_RETURN TTS_SetSpeed(HANDLE hTTS, int nSpeed);//value: 50 ~ 300; default 100
TTS_RETURN TTS_SetSampleRate(HANDLE hTTS, TTS_SAMPLE_RATE rate); //set sample rate, default TTS_SAMPLE_RATE_16K
TTS_RETURN TTS_Release(HANDLE hTTS); //release TTS handle
const char *TTS_GetVersion(void); //return version string
TTS_RETURN TTS_EnablePhraseFlush(HANDLE hTTS, int bEnabled);// 0: disable, otherwise: enable
int TTS_GetLanguage(HANDLE hTTS); //return language id
const int *TTS_GetAvailableLanguage(void); //return null-terminal array of language id
TTS_RETURN TTS_EnablePostFilter(HANDLE hTTS, int bEnabled);//default:false; Enable make quality better, but more cpu time

#endif
