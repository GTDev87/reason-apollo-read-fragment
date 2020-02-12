type queryObj = {
  .
  "query": ReasonApolloTypes.queryString,
  "variables": Js.Json.t,
};

type mutationObj = {
  .
  "mutation": ReasonApolloTypes.queryString,
  "variables": Js.Json.t,
};

type generatedApolloClient = {
  .
  "query":
    [@bs.meth] (queryObj => Js.Promise.t(ReasonApolloQuery.renderPropObjJS)),
  "mutate":
    [@bs.meth] (
      mutationObj => Js.Promise.t(ReasonApolloMutation.renderPropObjJS)
    ),
  "resetStore": [@bs.meth] (unit => Js.Promise.t(unit)),
};