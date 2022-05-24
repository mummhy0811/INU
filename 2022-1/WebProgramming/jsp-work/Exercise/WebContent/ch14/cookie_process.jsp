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
	String user_id=request.getParameter("id");
	String user_pw=request.getParameter("passwd");
	
	if(user_id.equals("admin") && user_pw.equals("1234")){
		Cookie cookie_id=new Cookie("userID", user_id);
		response.addCookie(cookie_id);
	}else{
		out.println("아이디와 비밀번호를 확인해주세요");
	}
	response.sendRedirect("welcome.jsp");
	%>
</body>
</html>