let fragmentMatcher: ApolloInMemoryCache.fragmentMatcher =
  ApolloInMemoryCache.createIntrospectionFragmentMatcher(
    ~data="GraphQLSchema.data", /* File here */
  );

  [@bs.val] external fetch: ApolloClient.fetch = "window.fetch";

/* Create an InMemoryCache */
let inMemoryCache: ReasonApolloTypes.apolloCache =
  ApolloInMemoryCache.createInMemoryCache(~fragmentMatcher, ());

/* Create an HTTP Link */

let httpLink: ReasonApolloTypes.apolloLink =
  ApolloLinks.createHttpLink(
    ~uri="https://example.com/api",
    ~fetch=fetch,
    ~headers=
      Json.Encode.object_([
        (
          "authorization",
          "Bearer JWT_TOKEN"
          |> Json.Encode.string,
        ),
      ]),
    (),
  );

let instance: ApolloClient.generatedApolloClient =
  ReasonApollo.createApolloClient(
    ~link=httpLink,
    ~cache=inMemoryCache,
    ~ssrMode=false,
    (),
  );