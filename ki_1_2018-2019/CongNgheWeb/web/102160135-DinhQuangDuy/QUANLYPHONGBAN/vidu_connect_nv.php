<?php 
//lay ma phong ban tu trang vidi_connect_pb.php
$mapb = $_REQUEST['IDPB'];
echo 'Ma phong ban nhan duoc: '.$mapb;
//khai bao ket noi
//bien ket noi
	$bienketnoi= mysqli_connect("localhost", "root", "") or die('khong the ket noi den CSDL MySQL: '
		.mysqli_error());

	$db_selected = mysqli_select_db($bienketnoi,"DULIEU");

	if ($mapb =="") {
		$rs = mysqli_query($bienketnoi,"select * from NHANVIEN");
	}

	else 
		{
			$rs = mysqli_query($bienketnoi,"select * from NHANVIEN where IDPB='$mapb'" );
		}

	echo '<table border="1" width="100%">';
	echo '<caption>Du Lieu bang Nhan Vien</Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

	echo "<TR><TH>Ma So</TH><TH>Ho Ten</TH><TH>Phong Ban</TH><TH>Dia Chi</TH> </TR>";

//cach 2: su dung hieu qua hon 

	while ($row=mysqli_fetch_array($rs,MYSQLI_BOTH)) {
	# code...
	
	echo '<tr>
	<td>'.$row['IDNV'].'</td>
	<td>'.$row['Hoten'].'</td>
	<td>'.$row['IDPB'].'</td>
	<td>'.$row['Diachi'].'</td></tr>';
}

echo "</TABLE>";

 ?>