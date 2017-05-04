// Include our libraries
var http = require('http');
var path = require('path');
var socketio = require('socket.io');
var express = require('express');
var router = express();
var server = http.createServer(router);
var io = socketio.listen(server);

// Use router to point requests to the 'files' folder 
router.use(express.static(path.resolve(__dirname, 'files')));
// Variables to hold the messages and the sockets

// Configure our Serial Port
var SerialPort = require('serialport');
var port = new SerialPort('/dev/tty.usbmodem1411', {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: SerialPort.parsers.readline("\r\n")
});

// CODE FOR SERIAL COMMUNICATION BELOW HERE


// Open the connection to the serial port
port.on('open', function () {
	console.log("Open Serial Communication");
	// Handles incoming data
		port.on('data', function (data) {
		console.log('Data: ' + data);
		io.emit('updateData', data);
	});
});


// CODE FOR SERIAL COMMUNICATION ABOVE HERE

// Use socket.io to send data between our server and webpage
io.on('connection', function (socket) {
    console.log("user connected to server");
});

// Start our server
server.listen(process.env.PORT || 3000, process.env.IP || "0.0.0.0", function () {
    var addr = server.address();
    console.log("Our server is listening at", addr.address + ":" + addr.port);
});