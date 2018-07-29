#ifndef _DEAL_H
#define _DEAL_H

#define lostline 0      //¶ªÏßÁÙ½çµç¸ĞÖµ£¬¿ÉÄÜÓÃ²»µ½


//±êÖ¾Î»Ã¶¾Ù
typedef enum
{
	FP=0,		//ÆÕÍ¨ÈüµÀ
	FCE=1,		//½øÈë»·µº±êÖ¾
	FCD=2,		//»·µºÄÚ±êÖ¾
	FT=3,		//Ê®×Ö±êÖ¾£¬¹À¼ÆÓÀ²»ÉÏ
}FLAG;


//extern ÉùÃ÷µÄ±äÁ¿²»ÄÜÔÚÉùÃ÷Ê±Ö±½Ó¸³Öµ£¬·ñÔòextern¾ÍÃ»ÓÃÁË

//±êÖ¾Î»
extern FLAG fg;

//´æ´¢Îå¸öµç¸ĞÖµµÄÊı¾İ£¬´òËã´Ó×óµ½ÓÒ0,1,2,3,4ÅÅĞò
extern uint16_t ADvalue[5],AD_Data[5],AD_cha,AD_he;

//xjbĞ´µÄ£¬ÓÃÓÚÔÚ²»ÖªµÀÌõ¼şÊ±±àÒë³ÌĞò²»±¨´í£
extern uint8_t condition;

//·½Ïò¿ØÖÆ´«²Î
extern int fvalue;
extern int last_value;

//´Ë´¦±¾´òËãÓÃferror£¬ÓÉÓÚºÍMDKµ×²ãÄ³ÎÄ¼ş×²Ãû×ÖÁË£¬¹ÊÉ¾È¥Ò»¸ör£¬¸ÄÎªferor
extern float feror;
extern float last_err;

//PID²ÎÊı£¬ÉèÖÃ³ÉÁË³¤¶ÈÎªÈıµÄ²ÎÊı£¬ÓÃÓÚÅäÖÃ¶àËÙ¶ÈµµÎ»»òÕßÆäËû²»Í¬Çé¿öÏÂµÄPIDÖµ
extern float kp[3],ki[3],kd[3];			

void DirectionControl(void);	

#endif