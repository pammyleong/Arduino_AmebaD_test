You need to build .c files under this folder with opus-1.3.1 to run this example.
This example uses a customized audio foramt:

2 bytes frame length + N bytes encoded opus data

Usually, opus data are contained in a container like ogg, and we provide examples using ogg as a container
to encode and decode audio data. So, this example is uploaded as a reference to meet some customers' special needs.