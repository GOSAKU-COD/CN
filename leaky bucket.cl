#include&lt;stdio.h&gt;

int main(){
int incoming, outgoing, buck_size, n, store = 0;
printf(&quot;Enter bucket size, outgoing rate and no of inputs: &quot;);
scanf(&quot;%d %d %d&quot;, &amp;buck_size, &amp;outgoing, &amp;n);

while (n != 0) {
printf(&quot;Enter the incoming packet size : &quot;);
scanf(&quot;%d&quot;, &amp;incoming);
printf(&quot;Incoming packet size %d\n&quot;, incoming);
if (incoming &lt;= (buck_size - store)){
store += incoming;

printf(&quot;Bucket buffer size %d out of %d\n&quot;, store, buck_size);
} else {
printf(&quot;Dropped %d no of packets\n&quot;, incoming - (buck_size -
store));
printf(&quot;Bucket buffer size %d out of %d\n&quot;, store, buck_size);
store = buck_size;
}
store = store - outgoing;
printf(&quot;After outgoing %d packets left out of %d in buffer\n&quot;, store,
buck_size);
n--;
}
}
