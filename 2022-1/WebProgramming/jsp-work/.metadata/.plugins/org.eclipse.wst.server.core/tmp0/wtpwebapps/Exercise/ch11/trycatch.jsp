<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Exception</title>
</head>
<body>
<%
	try{
		int i=1;
		i=i/0;
		out.println("결과: "+i);
	}
	catch(Exception e){
		out.println("오류 발생: "+e.getMessage());
	}
%>
</body>
</html>