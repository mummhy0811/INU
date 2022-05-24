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
	String name=request.getParameter("name");
	String address=request.getParameter("address");
	String pet=request.getParameter("pet");
	%>
	<p> <%=name %>님은 <%=address %>에 살고 있고
	<p> <%=pet %>을 좋아합니다.
</body>
</html>