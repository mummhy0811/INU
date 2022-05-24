<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Validation</title>
</head>
<script type="text/javascript">
	function checkPasswd(){
		let id=document.getElementById("id").value;
		let passwd=document.getElementById("passwd").value;
		if(id.length==0){
			alert("아이디를 입력해주세요");
			document.getElementById("id").focus();
			return;
		}
		if(passwd.length==0){
			alert("비밀번호를 입력해주세요");
			return;
		}
		if(passwd.indexOf(id)>-1){
			alert("비밀번호는 ID를 포함할 수 없습니다.");
			return;
		}
	}
</script>
<body>
	<form name="form" action="validation01_process.jsp" method="post">
		<p> 아 이 디 : <input type="text" name="id">
		<p> 비밀번호 : <input type="password" name="passwd">
		<p> <input type="submit" value="전송" onClick="checkPasswd()">
	</form>
</body>
</html>