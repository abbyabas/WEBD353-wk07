var SerialPort = require('serialport');
var port = new SerialPort('/dev/tty.usbmodem1411', {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: SerialPort.parsers.readline("\r\n")
});

port.on('data', function (data) {
    console.log('Data: ' + data);
});