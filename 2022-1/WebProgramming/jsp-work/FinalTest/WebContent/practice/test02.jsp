<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@page import="java.io.*, java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	response.setIntHeader("Refresh", 1);
	Calendar calendar=new GregorianCalendar();
	String am_pm;
	int hour=calendar.get(Calendar.HOUR);
	int minute=calendar.get(Calendar.MINUTE);
	int second=calendar.get(Calendar.SECOND);
	if(calendar.get(Calendar.AM_PM)==0) am_pm="AM";
	else am_pm="PM";
	String CT=hour+":"+minute+":"+second+":"+am_pm;
	out.println("현재 시간은: "+CT+"\n");
	%>
	<br>
	<p><a href="./test02_response.jsp">구글 홈페이지로 이동</a>
</body>
</html>