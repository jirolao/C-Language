#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct node{
  char data[MAX];
  struct node *link;
}*LIST;


void init(LIST *L);
void insert(LIST *L, char *str);
void show(LIST L);
void del(LIST *L, char *str);
void edit(LIST *L, char *oldstr, char *newstr);
void init(LIST *L){
  *L = NULL;
}


void insert(LIST *L, char *str){
  LIST *trav;
  LIST temp;
  for(trav = L; (*trav)!= NULL; trav = &amp;(*trav)-&gt;link);
  temp = malloc(sizeof(struct node));
  if (temp != NULL){
    strcpy(temp-&gt;data, str);
    temp-&gt;link = NULL;
    *trav = temp;
  }else{
    printf(&quot;\nFAILED TO ALLOCATE MEMORY\n&quot;);
  }
}


void insertSorted(LIST *L, char *str){
  LIST *trav;
  LIST temp;
  for(trav = L; (*trav)!= NULL &amp;&amp; (strcmp((*trav)-&gt;data, str) &lt; 0); trav =
&amp;(*trav)-&gt;link);
  temp = malloc(sizeof(struct node));
  if (temp != NULL){
    strcpy(temp-&gt;data, str);
    temp-&gt;link = (*trav);
    *trav = temp;
}else{
    printf(&quot;\nFAILED TO ALLOCATE MEMORY\n&quot;);
  }
}


void show(LIST L){
  LIST trav;
  for (trav = L; trav!=NULL; trav = trav-&gt;link){
    printf(&quot;%s \n&quot;, trav-&gt;data);
    if (trav-&gt;link != NULL){
      //printf(&quot;--&gt; &quot;);
    }
  }
}


void del(LIST *L, char *str){
  LIST *trav;
  LIST temp;
  for(trav = L; (*trav)!= NULL &amp;&amp; (strcmp((*trav)-&gt;data,str)!=0); trav =
&amp;(*trav)-&gt;link){}
  if (*trav!=NULL){
    temp = *(trav);
    *trav = (*trav)-&gt;link;
    free(temp);
  }else{
    printf(&quot;\nNOT FOUND!\n&quot;);
  }
}


void edit(LIST *L, char *oldstr, char *newstr){
  LIST *trav;
  LIST temp;
  for(trav = L; (*trav)!= NULL &amp;&amp; (strcmp((*trav)-&gt;data,oldstr)!=0); trav =
&amp;(*trav)-&gt;link){}
  if (*trav!=NULL){
    strcpy((*trav)-&gt;data, newstr);
  }else{
    printf(&quot;\nNOT FOUND!\n&quot;);
  }
}


void main(){
  LIST *head;
  init(&amp;head);
 	insertSorted(&amp;head, &quot;Farah&quot;);
 	insertSorted(&amp;head, &quot;Sakura&quot;);
	insertSorted(&amp;head, &quot;Kyle&quot;);
 	insertSorted(&amp;head, &quot;Christian&quot;);
 	insertSorted(&amp;head, &quot;Nicholas&quot;);
 	insertSorted(&amp;head, &quot;Athena&quot;);
 	insertSorted(&amp;head, &quot;Rei&quot;);
 	insertSorted(&amp;head, &quot;asdf&quot;);
 	show(head);
 	printf(&quot;\n&quot;);
 	del(&amp;head, &quot;asdf&quot;);
 	show(head);
 	printf(&quot;\n&quot;);
 	edit(&amp;head, &quot;Christian&quot;, &quot;Christian Maderazo&quot;);
 	show(head);
}
