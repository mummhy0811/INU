<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<style>
	.field{background-color:Linen;}
</style>
<body>
	<form action="animal_process.jsp" method="post">
		<fieldset class ="field">
			이 름 : <input type="text" name="name" size="10"> <br>
			주 소 : <input type="text" name="address" size="30"> <br>
			좋아하는 동물 : 
			<input type="checkbox" name="pet" value="dog">강아지</input>
			<input type="checkbox" name="pet" value="cat">고양이</input>
			<input type="checkbox" name="pet" value="pig">돼지</input><br><br>
			<input type="submit" value="전송">
		</fieldset>
	</form>
</body>
</html>