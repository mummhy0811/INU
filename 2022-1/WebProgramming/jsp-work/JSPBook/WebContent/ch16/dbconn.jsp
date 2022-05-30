<%@ page import="java.sql.*" %>
<%
		Connection conn=null;
	
		String url="jdbc:mysql://localhost:3306/JSPBookDB";
		String user="root";
		String password="root";
		
		Class.forName("com.mysql.jdbc.Driver");
		conn=DriverManager.getConnection(url, user, password);
		
%>