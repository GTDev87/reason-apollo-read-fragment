module type ReadFragment =
  (Config: ReasonApolloTypes.Config) =>
    {
      let read:
        (
          ~client: ApolloClientType.generatedApolloClient,
          ~id: string,
          ~fragmentName: string=?,
          unit
        ) =>
        option(Config.t);
    };

type readFragmentObj = {
  .
  "id": string,
  "fragment": ReasonApolloTypes.queryString,
  "fragmentName": Js.Nullable.t(string),
};

[@bs.send]
external readFragment: (ApolloClientType.generatedApolloClient, readFragmentObj) => Js.Nullable.t(Js.Json.t) = "";

module ReadFragment = (Config: ReasonApolloTypes.Config) => {
  [@bs.module] external gql: ReasonApolloTypes.gql = "graphql-tag";

  let read = (~client, ~id, ~fragmentName=?, ()): option(Config.t) =>
    client
    |> readFragment(
        _,
        {
          "id": id,
          "fragment": gql(. Config.query),
          "fragmentName": Js.Nullable.fromOption(fragmentName),
        },
      )
    |> Js.Nullable.toOption
    |> (
      fragmentDataOption =>
        switch (fragmentDataOption) {
        | None => None
        | Some(fragmentData) => Some(fragmentData |> Config.parse)
        }
    );
};