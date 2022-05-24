<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.util.Date"%>
<%@ page import = "java.text.SimpleDateFormat" %>
<%
	Date time=new Date();
	SimpleDateFormat formatter=new SimpleDateFormat("a HH:mm:ss");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	String session_id=session.getId();
	long last_time=session.getLastAccessedTime();
	long start_time=session.getCreationTime();
	long used_time=(last_time-start_time)/60000;
	%>
	세션 ID : <%=session.getId() %><br>
	<% time.setTime(start_time); %>
	요청 시작 시간 : <%=formatter.format(time) %><br>
	<% time.setTime(last_time); %>
	요청 시작 시간 : <%=formatter.format(time) %><br>
	웹 사이트에서 경과 시간: <%=used_time %>분
</body>
</html>