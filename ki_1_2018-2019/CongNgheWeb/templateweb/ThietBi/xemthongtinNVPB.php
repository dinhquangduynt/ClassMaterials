<?php
	$mapb=$_REQUEST['IDPB'];
	$bienketnoi=mysqli_connect('127.0.0.1', 'root', '') or die('Could not connect: '.mysqli_error());
	mysqli_select_db($bienketnoi, 'DULIEU');
	if($mapb=="")
		$rs=mysqli_query($bienketnoi, "select * from nhanvien");
	else
		$rs=mysqli_query($bienketnoi, "select * from nhanvien where IDPB='$mapb'");
	echo '<table border = "1" width = "100%">';
	echo '<caption>Du lieu truy xuat tu bang nhanvien</caption>';
	echo '<tr><th>IDNV</th><th>Hoten</th><th>IDPB</th><th>DiaChi</th></tr>';
	while($row=mysqli_fetch_array($rs)) {
		$idnv = $row{'IDNV'};
		$tennv = $row{'Hoten'};
		$idpb = $row{'IDPB'};
		$diachi = $row{'Diachi'};
		echo "<tr><td>$idnv</td><td>$tennv</td><td>$idpb</td><td>$diachi</td></tr>";

		// echo '<tr><td>'.row['IDNV'].'</td><td>'.row['Hoten'].'</td><td>'.row['IDPB'].'</td><td>'.row['DiaChi'].'</td></tr>';
	}
	echo '</table>';
	mysqli_free_result($rs);
	mysqli_close($bienketnoi);
?>