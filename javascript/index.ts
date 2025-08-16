import Fastify from "fastify";

const app = Fastify();

app.get("/ping", async (request, reply) => {
	return { message: "pong" };
});

app.listen({ port: 8080 }, (err, address) => {
	if (err) {
		console.error(err);
		process.exit(1);
	}
	console.log(`Server running at ${address}`);
});
