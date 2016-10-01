Instruction
~~~~~~~~~~~

You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.Each student can have multiple answer sheets.So the teacher has :math:`X` queries:

1 :math:`X Y`: Add the marks :math:`Y` to the student whose name is :math:`X`.

2 :math:`X`: Erase the marks of the students whose name is :math:`X`.

3 :math:`X`: Print the marks of the students whose name is :math:`X`. (If  didn't get any marks print :math:`0`.)

Input Format
~~~~~~~~~~~~

The first line of the input contains :math:`Q` where :math:`Q` is the number of queries. The next :math:`Q` lines contain `1` query each.The first integer, :math:`type` of each query is the type of the query. If query is of type :math:`1`, it consists of one string and an integer :math:`X` and :math:`Y` where :math:`X` is the name of the student and :math:`Y` is the marks of the student. If query is of type :math:`2` or :math:`3`, it consists of a single string :math:`X` where :math:`X` is the name of the student.

Constraints
~~~~~~~~~~~

|  :math:`1<=Q<=10^5`
|  :math:`1<=type<=3`
|  :math:`1<=|X|<=6`
|  :math:`1<=Y<=10^3`



Output Format
~~~~~~~~~~~~~

For queries of type :math:`3` print the marks of the given student.

Sample Input
~~~~~~~~~~~~
|  7
|  1 Jesse 20
|  1 Jess 12
|  1 Jess 18
|  3 Jess
|  3 Jesse
|  2 Jess
|  3 Jess

Sample Output
~~~~~~~~~~~~~
|  30
|  20
|  0
