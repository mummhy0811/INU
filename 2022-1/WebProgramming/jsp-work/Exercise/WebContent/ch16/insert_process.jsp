<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Database SQL</title>
</head>
<body>
	<%@ include file="dbconn.jsp" %>
	<%
	request.setCharacterEncoding("utf-8");
	
	String num=request.getParameter("num");
	String depart=request.getParameter("depart");
	String name=request.getParameter("name");
	String address=request.getParameter("address");
	String phone=request.getParameter("phone");
	
	PreparedStatement pstmt=null;
	
	try{
		String sql="INSERT INTO Student(num, depart, name, address, phone) VALUES( ?, ?, ?, ?, ?)";
		pstmt=conn.prepareStatement(sql);
		pstmt.setString(1, num);
		pstmt.setString(2, depart);
		pstmt.setString(3, name);
		pstmt.setString(4, address);
		pstmt.setString(5, phone);
		pstmt.executeUpdate();
		out.println("Student 테이블 삽입이 성공했습니다.");
	}catch(SQLException ex){
		out.println("Student 테이블 삽입이 실패했습니다.<br>");
		out.println("SQLException: "+ ex.getMessage());
	}finally{
		if(pstmt != null) 
			pstmt.close();
		if(conn!=null) 
			conn.close();
	}
	%>
</body>
</html>