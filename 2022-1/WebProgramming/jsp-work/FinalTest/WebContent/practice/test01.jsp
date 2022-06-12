<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form action="test01_process.jsp" method="post">
	<fieldset>
	<legend>수강신청</legend>
		<p> 학 과 명 : <input type="text" name="apply_Class">
		<p> 신청과목 1 : <input type="text" name="apply_Subject1">
			신청인원 : <input type="number" name="allpy_Count1">
		<p> 신청과목 2 : <input type="text" name="apply_Subject2">
			신청인원 : <input type="number" name="allpy_Count2">
		<p> <input type="submit" value="전송"/>
	</fieldset>
	</form>
</body>
</html>