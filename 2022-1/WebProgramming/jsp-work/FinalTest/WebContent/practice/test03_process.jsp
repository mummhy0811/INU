<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("utf-8");
	%>
	<p> 아이디 : &nbsp;&nbsp; <%=request.getParameter("id") %>
	<p> 비밀번호 : <%=request.getParameter("passwd") %>
</body>
</html>