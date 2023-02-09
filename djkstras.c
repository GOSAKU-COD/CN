#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
void dijkstras();
int c[10][10],n,src;
void main()
{
int i,j;
printf(&quot;\nenter the no of vertices:\t&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nenter the cost matrix:\n&quot;);
for(i=1;i&lt;=n;i++)
{
for(j=1;j&lt;=n;j++)
{
scanf(&quot;%d&quot;,&amp;c[i][j]);
}
}
printf(&quot;\nenter the source node:\t&quot;);
scanf(&quot;%d&quot;,&amp;src);

dijkstras();

}
void dijkstras()
{
int vis[10],dist[10],u,j,count,min;
for(j=1;j&lt;=n;j++)
{
dist[j]=c[src][j];
}
for(j=1;j&lt;=n;j++)
{
vis[j]=0;
}
dist[src]=0;
vis[src]=1;
count=1;
while(count!=n)
{
min=9999;
for(j=1;j&lt;=n;j++)
{
if(dist[j]&lt;min&amp;&amp;vis[j]!=1)
{
min=dist[j];
u=j;

}
}
vis[u]=1;
count++;
for(j=1;j&lt;=n;j++)
{
if(min+c[u][j]&lt;dist[j]&amp;&amp;vis[j]!=1)
{
dist[j]=min+c[u][j];
}
}
}
printf(&quot;\nthe shortest distance is:\n&quot;);
for(j=1;j&lt;=n;j++)
{
printf(&quot;;\n%d-----&gt;%d=%d&quot;,src,j,dist[j]);
}
}
