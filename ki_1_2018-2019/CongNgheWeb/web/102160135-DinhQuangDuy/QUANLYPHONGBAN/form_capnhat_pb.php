<?php 
	$mapb=$_REQUEST['IDPB'];
	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$rs=mysqli_query($link, "select * from phongban where IDPB='$mapb'");
	$row=mysqli_fetch_array($rs);
	mysqli_free_result($rs);
    mysqli_close($link);
 ?>

<html>
	<head>
		<title>Cap nhat phong ban</title>
	</head>
	<body>
		<center>
			<form name="f1" action="xulycapnhat.php?IDPB=<?php echo $row['IDPB'];?>" method="POST">
			<table width="400px" border="0">
				<?php  echo '<tr>
						<td> phong Ban</td>
						<td>'.$mapb.'</td>
						</tr>';?>
				<tr>
					<td>Mo ta</td>
					<td><input type="Text" size="20" name="txtMoTa"></td>
				</tr>
				<tr>
					<td>Thoi gian</td>
					<td><input type="date" name="thoigian"></td>
				</tr>
				
			</table>
		
					<input type="Submit" name="b1" value="OK">
					<input type="Reset" name="b2" value="Reset">
			
		</form>
		</center>
	</body>
</html>

	
	

