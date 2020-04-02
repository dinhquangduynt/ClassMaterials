<?php
	$myID=$_REQUEST["IDPB"];
	$bienketnoi=mysqli_connect("127.0.0.1", "root", "") or die('Could not connect: '.mysqli_error());
	$db_selected=mysqli_select_db($bienketnoi, "DULIEU");
	$rs=mysqli_query($bienketnoi, "select * from phongban where IDPB='$myID'");
	$row=mysqli_fetch_array($rs);
?>
<html>
	<head>
		<title>Cap nhat phong ban</title>
	</head>
	<body>
		<form action='xulycapnhat.php?IDPB=<?php echo $row['IDPB'];?>' method='post'>
			<table width="100%" border="0">
				<tr>
					<td>Ma phong ban</td>
					<td><input type="Text" size="20" name="txtMaPB" value="<?php echo $row['IDPB'];?>"></td>
				</tr>
				<tr>
					<td>Ten phong ban</td>
					<td><input type="Text" size="20" name="txtTenPB"></td>
				</tr>
				<tr>
					<td>Mo ta</td>
					<td><input type="Text" size="20" name="txtMoTa"></td>
				</tr>
				<tr>
					<td><input type="Submit" name="b1" value="OK"></td>
					<td><input type="Reset" name="b2" value="Reset"></td>
				</tr>
			</table>
		</form>
	</body>
</html>