<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page isErrorPage="true" %>
    
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Exception</title>
</head>
<body>
	<p>오류가 발생하였습니다.
	<p>예외 : <%=exception %>
	<p>toString(): <%=exception.toString() %>
	<p>getClass().getName():<%=exception.getClass().getName() %>
	<p>getMessage():<%=exception.getMessage() %>
</body>
</html>