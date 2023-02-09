#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define N
strlen(gen_poly)
char data[28];
char check_value[28];
char gen_poly[10];
int data_length,i,j;
void XOR(){
for(j = 1;j &lt; N; j++)
check_value[j] = (( check_value[j] ==
gen_poly[j])?&#39;0&#39;:&#39;1&#39;);
}

void receiver()

{

printf(&quot;Enter the received data: &quot;);
scanf(&quot;%s&quot;, data);

printf(&quot;\n-----------------------------\n&quot;);
printf(&quot;Data received: %s&quot;, data); crc();
for(i=0;(i&lt;N-1) &amp;&amp;
(check_value[i]!=&#39;1&#39;);i++); if(i&lt;N-1)
printf(&quot;\nError detected\n\n&quot;); else
printf(&quot;\nNo error detected\n\n&quot;);}

void crc(){
for(i=0;i&lt;N;i++)
check_value[i]=data[i];
do{
if(check_value[0]==&#39;1&#39;)
XOR();
for(j=0;j&lt;N-1;j++)
check_value[j]=check_value[j+1];
check_value[j]=data[i++];
}while(i&lt;=data_length+N-1);
}
int main()
{

printf(&quot;\nEnter data to be transmitted: &quot;);
scanf(&quot;%s&quot;,data);
printf(&quot;\n Enter the Generating polynomial:
&quot;);
scanf(&quot;%s&quot;,gen_poly);
data_length=strlen(data);
for(i=data_length;i&lt;data_length+N-1;i++)
data[i]=&#39;0&#39;;
printf(&quot;\n----------------------------------------&quot;);
printf(&quot;\n Data padded with n-1 zeros :
%s&quot;,data);
printf(&quot;\n----------------------------------------&quot;);
crc();
printf(&quot;\nCRC or Check value is :
%s&quot;,check_value);
for(i=data_length;i&lt;data_length+N-1;i++)
data[i]=check_value[i-data_length];
printf(&quot;\n----------------------------------------&quot;);
printf(&quot;\n Final data to be sent : %s&quot;,data);
printf(&quot;\n----------------------------------------\n&quot;);
receiver();
return 0;
}
