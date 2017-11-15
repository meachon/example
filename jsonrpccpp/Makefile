

all:
	g++ server.cpp -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -o sampleserver
	g++ client.cpp -ljsoncpp -lcurl -ljsonrpccpp-common -ljsonrpccpp-client -o sampleclient
	
.PYONY: clean

clean:
	rm -rf sampleclient 
	rm -rf sampleserver
