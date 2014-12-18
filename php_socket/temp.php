<?php

$command = "info"
if (!$_socket = @fsockopen("udp://" . "183.60.15.153", "27018", $errno, $errstr, 1000)) 
{
	if (!fwrite($this->_socket, "xFFxFFxFFxFF" . $command . "x00")) echo "send false\n";
		echo "send true\n";

	if (!fclose($_socket)) 
		echo "close false\n";
	else
		echo "close true\n";
}
