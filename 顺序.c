#include<stdio.h>
#include<stdlib.h>

lll

#define InitSize 10
#define ElemType int
typedef struct SeqList{
    ElemType* data;
    int MaxSize,length;
}SeqList;

// 1.初始化
void InitList(SeqList &L){
    L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
    L.MaxSize = InitSize;
    L.length = 0;
    printf("顺序表初始化成功！\n");
}

// 2.求表长
int Length(SeqList L){
    return L.length;
}

// 3.判空
bool Empty(SeqList L){
    if(L.length == 0){
        printf("顺序表为空！\n");
        return true;
    }else{
        printf("顺序表非空！");
        return false;
    }
}

// 4.增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ElemType)*L.MaxSize+len);
    for(int i=0;i<L.length;i++){
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

// 5.按位查找
ElemType GetElem(SeqList L,int i){
    if(i<1 || i>L.length)
        return -1;
    return L.data[i-1];
}

// 6.插入
bool ListInsert(SeqList &L,int i, ElemType e){
    if(i<1 || i>L.length+1){
        return false;
    }
    if(L.length>=MaxSize){
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//7.删除
bool ListDelete(SeqList &L,int i,ElemType &e){
    if(i<1 || i>L.length){
        return false;
    }
    e = L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//8.按值查找
int LocateElem(SeqList L,ElemType e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//9.遍历
void PrintList(SeqList L){
    printf("遍历开始");
    for(int i=0;i<L.length;i++)
        printf("%d\t",L.data[i]);
    printf("\n");
}


int main(){
    int n,i;
    ElemType a,e = -1;
    SeqList L;
    InitList(L);
    Empty(L);

    printf("请输入插入元素个数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(ListInsert(L,i+1,a))
            printf("插入成功第%d个元素:%d",i+1,a);
        else
            printf("第%d个元素插入失败",i+1);
    }

    Empty(L);

    PrintList(L);

    printf("请输入您要删除元素的位序i：");
	scanf("%d", &i);
	if (ListDelete(L, i, e))
		printf("已删除第%d个元素，其值为：%d\n", i, e);
	else
		printf("位序i不合法,删除失败！\n");

    /*5、输出当前表长*/
	printf("当前表长为:%d\n",Length(L));

	/*6、遍历当前顺序表*/
	PrintList(L);

	/*7、按位查找*/
	printf("请输入您要查找元素的位序i：");
	scanf("%d",&i);
	if (GetElem(L, i) == -1)
		printf("您输入的位序不合法！");
	else
		printf("位序为%d的值为：%d\n", i, GetElem(L, i));

	/*8、按值查找*/
	printf("请输入您要查找元素的值：");
	scanf("%d", &a);
	printf("值为%d的元素第一次出现的位序为：%d\n", a, LocateElem(L, a));
    return 0;
}
