from school_api import SchoolClient
school = SchoolClient(url='教务处网址')
student = school.user_login('账号','密码',timeout=10)
term = input("请输入第几学期? [1/2]")
score_data = student.get_score(score_year='2018-2019',score_term=term,use_api=1)
for i in score_data:
    print("课程："+i['lesson_name'],"分数："+str(i['score']),"绩点："+str(i['point']),"学分："+str(i['credit']))
