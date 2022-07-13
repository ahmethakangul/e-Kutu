<?php
include('ayar1453.php');
if(isset($_GET['deger1'] ))
{$s1d= $_GET['deger1'];
$s2d= $_GET['deger2'];
$s3d= $_GET['deger3'];

 $zmn = time();
 $ip = $_SERVER['REMOTE_ADDR'];
  $a=mysqli_query($bag,"INSERT  INTO sicakliklar (sID, sTime, sSensor1, sSensor2, sSensor3, sIp) VALUES (NULL, '$zmn', '$s1d', '$s2d','$s3d',  '$ip');");
  if ($a)
	echo '1';
  else
	echo '0';
}

?>
