<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Database SQL</title>
</head>
<body>
<%@include file="dbconn.jsp" %>
	<table width="300" border="1">
		<tr>
		<th>학번</th>
		<th>학과</th>
		<th>이름</th>
		<th>주소</th>
		<th>연락처</th>
		</tr>
		<%
		ResultSet rs=null;
		PreparedStatement pstmt=null;
		try{
			String sql="select * from Student";
			pstmt=conn.prepareStatement(sql);
			rs=pstmt.executeQuery();
			while(rs.next()){
				String num=rs.getString("num");
				String depart=rs.getString("depart");
				String name=rs.getString("name");
				String address=rs.getString("address");
				String phone=rs.getString("phone");
		%>
		<tr>
			<td><%=num %></td>
			<td><%=depart %></td>
			<td><%=name %></td>
			<td><%=address %></td>
			<td><%=phone %></td>
		</tr>
		<%
			}
		}catch(SQLException ex){
			out.println("Student 테이블 호출이 실패했습니다.<br>");
			out.println("SQLException: "+ex.getMessage());
		}finally{
			if(rs!=null) rs.close();
			if(pstmt!=null) pstmt.close();
			if(conn!=null) conn.close();
		}
		%>
		
	</table>
</body>
</html>