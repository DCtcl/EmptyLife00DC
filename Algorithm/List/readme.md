链表的基本操作

# Input
输入数据只有一组，第一行有n+1个整数，第一个整数是这行余下的整数数目n，后面是n个整数。
这一行整数是用来初始化列表的，并且输入的顺序与列表中的顺序相反，也就是说如果列表中是1、2、3那么输入的顺序是3、2、1。
第二行有一个整数m，代表下面还有m行。每行有一个字符串，字符串是“get”，“insert”，“delete”，“show”中的一种。

- 如果是“get”，代表获得第a个元素。（a从1开始计数）
- 如果是“delete”，代表删除第a个元素。（a从1开始计数）
- 如果是“insert”，则其后跟着两个整数a和e，代表在第a个位置前面插入e。（a从1开始计数）
- “show”之后没有正数，直接打印链表全部内容。

# Output
- 如果获取成功，则输出该元素，否则输出“get fail”；
- 如果删除成功，则输出“delete OK”，否则输出“delete fail”；
- 如果插入成功，则输出“insert OK”，否则输出“insert fail”。
- 如果是“show”，则输出列表中的所有元素，如果列表是空的，则输出“Link list is empty”
注：所有的双引号均不输出。

# 样例输入
3 3 2 1
21
show
delete 1
show
delete 2
show
delete 1
show
delete 2
insert 2 5
show
insert 1 5
show
insert 1 7
show
insert 2 5
show
insert 3 6
show
insert 1 8
show
get 2

# 样例输出
1 2 3
delete OK
2 3
delete OK
2
delete OK
Link list is empty
delete fail
insert fail
Link list is empty
insert OK
5
insert OK
7 5
insert OK
7 5 5
insert OK
7 5 6 5
insert OK
8 7 5 6 5
7
