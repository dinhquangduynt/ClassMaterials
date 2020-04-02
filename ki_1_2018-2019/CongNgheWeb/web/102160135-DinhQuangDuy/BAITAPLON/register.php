<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>

	<center>
		<form name="f1" action="xulyregister.php" method="POST">
			<table width="600px" border="0">

				<tr>
					<td>Họ và tên</td>
					<td><input type="Text" size="20" name="txtten"></td>
				</tr>
				<tr>
					<td>Tên đăng nhập</td>
					<td><input type="Text" size="20" placeholder="Username" name="txtuser"></td>
				</tr>
				<tr>
					<td>Mật khẩu</td>
					<td><input type="Password" size="20" placeholder="Password" name="txtpass"></td>
				</tr>
				<tr>
					<td>Nhập lại mật khẩu</td>
					<td><input type="Password" size="20" placeholder="Password" name="txtpass"></td>
				</tr>
				<tr>
					<td>Số điện thoại</td>
					<td><input type="text" size="20" name="txtsdt"></td>
				</tr>
			
			</table>
			<input type="Submit" name="b1" value="Đăng kí">
			<input type="Reset" name="b2" value="Reset">
		</form>
	</center>

</body>
</html>