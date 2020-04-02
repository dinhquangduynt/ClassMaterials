<?php 
	$ten=$_POST['t1'];

	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_select_db($link,"DULIEU");
	$sql="select *from NHANVIEN WHERE Hoten like '%$ten' OR Hoten like '$ten%' OR IDNV='%$$ten' OR IDNV='$$ten%' ";
	$rs=mysqli_query($link,$sql);
	if (mysqli_num_rows($rs) == 0)
	{
		echo '<script language="javascript">alert("Không có thông tin"); 
            window.location="timkiem.php";</script>';
	}
	else{
		echo '<table border="1" width="100%">';
		echo '<caption>Du Lieu Tim Kiem</Caption>';
//tieu de cua bang chua du lieu  khi hienthi trang web

		echo "<TR><TH>Ma So</TH><TH>Ho Ten</TH><TH>Phong Ban</TH><TH>Dia Chi</TH> </TR>";
		while ($row=mysqli_fetch_array($rs,MYSQLI_BOTH)) {
			
			echo '<tr>
			<td>'.$row['IDNV'].'</td>
			<td>'.$row['Hoten'].'</td>
			<td>'.$row['IDPB'].'</td>
			<td>'.$row['Diachi'].'</td></tr>';
		}

		echo "</TABLE>";
	}
 ?>