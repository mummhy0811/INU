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
	if(user_id.equals("admin") && user_pw.equals("admin123")){
		session.setAttribute("userID", user_id);
		response.sendRedirect("welcome.jsp");
	}else{
		out.println("아이디와 비밀번호를 확인해 주세요");
	}
	%>
</body>
</html>