#include<stdio.h>

int main(){
int h1, m1, s1, h2, m2, s2, h3, m3, s3;

scanf(" %d:%d:%d", &h1, &m1, &s1);
scanf(" %d:%d:%d", &h2, &m2, &s2);

if(h1>=0 && h1<=23 && h2>=0 && h2<=23 && m1>=0 && m1<=59 && m2>=0 && m2<=59 && s1>=0 && s1<=59 && s2>=0 && s2<=59){
if(h1>h2){
	h3=h1-h2;
	if(m2>m1){
		h3--;
		m3=(m2+m1)%60;
		if(s2>s1){
			m3--;
			s3=(s1+s2)%60;
		}
		else
		s3=(s1-s2);	
	}
	else{
		m3=(m1-m2);
		if(s2>s1){
			m3--;
			s3=(s1+s2)%60;
		}
		else
		s3=(s1-s2);
	}
		
}
else{
	h3=h2-h1;
	
	if(m2<m1){
		h3--;
		m3=(m2+m1)%60;
		if(s2<s1){
			m3--;
			s3=(s1+s2)%60;
		}
		else
		s3=(s2-s1);	
	}
	else{
		m3=(m2-m1);
		if(s2<s1){
			m3--;
			s3=(s1+s2)%60;
		}
		else
		s3=(s2-s1);
	}
		
}

printf("%d:%d:%d\n", h3,m3,s3);
}
else
	printf("Non valido");
return 0;
}
