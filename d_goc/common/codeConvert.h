#ifndef _CODE_CONVERT_H_
#define _CODE_CONVERT_H_
#include <iconv.h>
#include <string.h>
//代码转换:从一种编码转为另一种编码 
inline int code_convert(const char *from_charset, const char *to_charset,char *inbuf,int inlen,char *outbuf,int outlen) 
{ 
	 iconv_t cd; 
	 int rc; 
	 char **pin = &inbuf; 
	 char **pout = &outbuf; 
	 size_t iSrcLen=inlen;
	 size_t iOutLen=outlen;
	 cd = iconv_open(to_charset,from_charset); 
	 if (cd==0) return -1; 
	 memset(outbuf,0,outlen); 
	 if (iconv(cd,pin,&iSrcLen,pout,&iOutLen)==-1) return -1; 
	 iconv_close(cd); 
	 return 0; 
}

//UNICODE码转为GB2312码 
inline int u2g(char *inbuf,int inlen,char *outbuf,int outlen) 
{ 
	const char *from = "utf-8";
	const char *to = "gb2312";
	return code_convert(from, to, inbuf, inlen, outbuf, outlen); 
}

//GB2312码转为UNICODE码 
inline int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen) 
{ 
	const char *from = "utf-8";
	const char *to = "gb2312";	
	return code_convert(to, from, inbuf, inlen, outbuf, outlen); 
} 
#endif