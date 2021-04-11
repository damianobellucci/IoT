import React, { useEffect } from 'react';
import mqtt from 'mqtt';

const IPbroker = 'mqtt://130.136.2.70:1883'
const topic_1 = 'temperature/damianobellucci'
const options = {
    clientId: 'clientJSsub',
    protocolId: 'MQIsdp',
    protocolVersion: 3,
    connectTimeout: 1000,
    debug: true,
    username: 'IOTuser',
    password: 'IOTuser',
    retain: true,
    qos: 1
};


export default function Mqtt() {
    const [connectionStatus, setConnectionStatus] = React.useState(false);
    const [messages, setMessages] = React.useState([]);

    useEffect(() => {
        const client = mqtt.connect(IPbroker, options);
        client.on("error", function (error) {
            console.log("Can't connect" + error);
        });
        client.on('connect', () => setConnectionStatus(true));
        client.on('message', (topic, payload, packet) => {
            setMessages(messages.concat(payload.toString()));
        });
        client.subscribe(topic_1)
    }, []);

    return (
        <>aaa {connectionStatus} </>
    )
}